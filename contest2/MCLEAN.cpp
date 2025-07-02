#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
#define Y second
#define X first
string a[maxn];
#define rei(i,a,b) for(int i=a;i<=b;i++) 
int n,m;
int _x[4]={1,0,-1,0};
int _y[4]={0,1,0,-1};
int d[maxn][maxn][maxn][maxn];
void calc(int sx,int sy){
    rei(i,1,n) rei(j,1,m) d[sx][sy][i][j]=1e9;
    d[sx][sy][sx][sy]=0;
    queue<pair<int,int>> q;
    q.push({sx,sy});
    while(!q.empty()){
        int x=q.front().X;
        int y=q.front().Y;
        q.pop();
        rei(i,0,3){
            int nx=x+_x[i];
            int ny=y+_y[i];
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m){
                if(a[nx][ny]!='x'){
                    if(d[sx][sy][nx][ny]>d[sx][sy][x][y]+1){
                        d[sx][sy][nx][ny]=d[sx][sy][x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
}
vector<pair<int,int>> ncbfs;
int dp[1<<20][21];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("MCLEAN.INP","r")){
        freopen("MCLEAN.INP","r",stdin);
        freopen("MCLEAN.OUT","w",stdout);
    }
    cin>>n>>m;
    swap(n,m);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]=" "+a[i];
    pair<int,int> r={0,0};
    rei(i,1,n){
        rei(j,1,m){
            if(a[i][j]=='*') ncbfs.push_back({i,j});
            if(a[i][j]=='o') r={i,j};
        }
    }
    calc(r.X,r.Y);
    for(pair<int,int> x:ncbfs) calc(x.X,x.Y);
    int lim=ncbfs.size();
    rei(i,1,lim) rei(x,0,(1<<lim)-1) dp[x][i]=1e9;
    rei(i,1,lim) dp[1<<(i-1)][i]=d[r.X][r.Y][ncbfs[i-1].X][ncbfs[i-1].Y];
    rei(x,0,(1<<lim)-1){
        rei(i,1,lim) if(getbit(i,x)){
            rei(j,1,lim) if(!getbit(j,x)){
                int y=x|(1<<(j-1));
                dp[y][j]=min(dp[y][j],dp[x][i]+d[ncbfs[i-1].X][ncbfs[i-1].second][ncbfs[j-1].X][ncbfs[j-1].Y]);
            }
        }
    }
    int ds=1e9;
    rei(i,1,lim) ds=min(ds,dp[(1<<lim)-1][i]);
    if(ds>=1e9) cout<<"-1";
    else cout<<ds;
}
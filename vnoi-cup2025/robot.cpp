/*
cho bang n*m o (i,j) co 1 ky tu thuoc tap sau R,L,U,D tim so cach thay doi it nhat de co the di duoc tu (x1,y1)---->(x2,y2) neu co nhieu phuong an hay dem so phuong an
so cach chia cho 10^9+7
*/ 
/*
dp[i][j][x][y] so cach thay doi it nhat de co the di tu (i,j) den (x,y) 
sang o (nx,ny) neu (nx,ny) ke voi (x,y)-->dp[i][j][nx][ny]=dp[i][j][x][y];
neu khong ke dp[i][j][nx][ny]=dp[i][j][nx][ny]+1;
int cnt[i][j][x][y] phuong an thay doi it nhat de  co duong di tu tu (i,j) --> (x,y)
=> so phuong an toi uu tu (i,j) --> (nx,ny)
neu (nx,ny) ke voi (x,y){
    neu dp[i][j][nx][ny]==dp[i][j][x][y] ---> cnt[i][j][nx][ny]+=cnt[i][j][x][y];
}
neu khong thi{
    neu dp[i][j][nx][ny]=dp[i][j][x][y]+1 cnt[i][j][nx][ny]+=cnt[i][j][x][y];
}
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,q;
typedef long long ll;
#define rei(i,a,b) for(int i=a;i<=b;i++) 
#define mp make_pair
const int mod=1e9+7;
const int maxn = 1e3+1;
ll dp[maxn][maxn],cnt[maxn][maxn];
int _x[4]={1,0,-1,0};
int _y[4]={0,1,0,-1};
string dd="DRUL";
string a[maxn];
bool ok(int x,int y,int nx,int ny){
    rei(i,0,3){
        int tmpx=x+_x[i];
        int tmpy=y+_y[i];
        if(dd[i]==a[x][y]){
            return (tmpx==nx)&&(tmpy==ny);
        }
    }
    return 0;
}
void calcdp(int sx,int sy){
    rei(i,1,n) rei(j,1,m){
        dp[i][j]=1e18;
        
    }
    dp[sx][sy]=0;
    priority_queue<pair<ll,pair<int,int>>> q;
    q.push(mp(0,mp(sx,sy)));
    //q.push({sx,sy});
    while(!q.empty()){
        int x=q.top().second.first;
        int y=q.top().second.second;
        q.pop();
        rei(i,0,3){
            int nx=x+_x[i];
            int ny=y+_y[i];
            if(1<=nx&&nx<=n && 1<=ny&&ny<=m) {
                if(ok(x,y,nx,ny)){
                    if(dp[nx][ny]>dp[x][y]){
                        dp[nx][ny]=dp[x][y];
                        q.push(mp(dp[nx][ny],mp(nx,ny)));
                        
                    }
                }
                if(dp[nx][ny]>dp[x][y]+1){
                    dp[nx][ny]=dp[x][y]+1;
                    q.push(mp(dp[nx][ny],mp(nx,ny)));
                    
                }
            }
        }
    }
}
void calccnt(int x,int y){
    /// ??????
}
void solve(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    memset(cnt,0,sizeof(cnt));
    cnt[sx][sy]=1;
    calcdp(sx,sy);
    cout<<dp[tx][ty]<<" "<<cnt[tx][ty]<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n) a[i]=" "+a[i];
    calcdp(1,1);
    rei(i,1,n){
        rei(j,1,m) cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    rei(i,1,n){
        rei(j,1,m) cout<<cnt[i][j]<<" ";
        cout<<'\n';
    }
    /*while(q--){
        solve();
    }*/
}
/*3 4 2
RDRD
RDRD
UUUL
1 1 3 2
1 1 3 4*/
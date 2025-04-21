#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
const int mod=1e9+7;
typedef long long ll;
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ub upper_bound
#define lb lower_bound
int _x[4]={0,0,-1,1};
int _y[4]={1,-1,0,0};
string D="RLUD";
int n,m,k;
//pair<int,int> a[maxn];
int a[maxn][maxn];
pair<int,int> r[maxn];
pair<int,int> pre[maxn][maxn];
bool vis[maxn][maxn];
char getp(pair<int,int> u,pair<int,int> v){
    rei(i,0,3){
        if(u.first-v.first==_x[i]&&u.second-v.second==_y[i]) return D[i];
    }
}
pair<int,int> con(char x,pair<int,int> u){
    for(int i=0;i<4;i++){
        if(D[i]==x) return {u.first+_x[i],u.second+_y[i]};
    }
    return u;
}
void sub2(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int nx=x+_x[i];
        int ny=y+_y[i];
        if(!vis[nx][ny]){
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m){
                if(!a[nx][ny]){
                    pre[nx][ny]={x,y};
                    sub2(nx,ny);
                }
            }
        }
    }
}
int main(){
	faster
    cin>>n>>m>>k;
    rei(i,1,n) rei(j,1,m) cin>>a[i][j];
    rei(i,1,k) cin>>r[i].first>>r[i].second;
    sub2(r[n].first+1,r[n].second+1);
    string p;
    pair<int,int> dinh={r[n].first+1,r[n].second+1};
    pair<int,int> dx={1,1};
    while(dinh!=dx){
        p=string(1,getp(dx,pre[dx.first][dx.second]))+p;
        dx=pre[dx.first][dx.second];
    }
    cout<<p;

	return 0;
}

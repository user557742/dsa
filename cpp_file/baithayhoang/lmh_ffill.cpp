#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+1;
int n,m;
string s[maxn];
int a[maxn][maxn];
int _x[4]={0,1,0,-1};
int _y[4]={1,0,-1,0};
bool vis[maxn][maxn];
void dfs(int x,int y,int cl,int bs){
    vis[x][y]=1;
    a[x][y]=cl;
    for(int i=0;i<4;i++){
        int nx=_x[i]+x;
        int ny=_y[i]+y;
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m){
            if(vis[nx][ny]==0&&a[nx][ny]==bs){
                dfs(nx,ny,cl,bs);
            }
        }
    }
}
int sl=0;
void calc(int x,int y,int mau){
    vis[x][y]=1;
    sl++;
    for(int i=0;i<4;i++){
        int nx=_x[i]+x;
        int ny=_y[i]+y;
        if(1<=nx&&nx<=n&&1<=ny&&ny<=m){
            if(vis[nx][ny]==0&&a[nx][ny]==mau){
                calc(nx,ny,mau);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) s[i]=" "+s[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        if(s[i][j]=='W') a[i][j]=0;
        else a[i][j]=1;
    }
    int q;cin>>q;
    while(q--){
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
        char x;int i,j;cin>>x>>i>>j;
        int mau=(x=='W') ? 0 : 1;
        dfs(i,j,mau,a[i][j]);
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) vis[i][j]=0;
        int ds=0;
        int ds2=0;
        for(int u=1;u<=n;u++){
            for(int v=1;v<=m;v++){
                if(!vis[u][v]){
                    sl=0;
                    ds++;
                    calc(u,v,a[u][v]);
                    ds2=max(ds2,sl);
                }
            }
        }
        cout<<ds<<" "<<ds2<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn =1e3+1;
int a[maxn][maxn];
int l[maxn],r[maxn];
int n,m,h[maxn];
int main(){
    if(fopen("flatland.inp","r")){
        freopen("flatland.inp","r",stdin);
        freopen("flatland.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    int ds=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            r[j]=0;l[j]=0;
        }
        for(int j=1;j<=m;j++){
            if(a[i-1][j]!=a[i][j]) h[j]=1;
            else h[j]=h[j]+1;
        }
        for(int u=1;u<=m;u++){
            int v=u-1;
            while(v>0&&h[v]>=h[u]&&a[i][v]==a[i][u]) v=l[v];
            l[u]=v;
        }
        for(int u=m;u>=1;u--){
            int v=u+1;
            while(v<m&&h[v]>=h[u]&&a[i][v]==a[i][u]) v=r[v];
            r[u]=v;
        }
        for(int j=1;j<=m;j++){
            l[j]+=1;
            r[j]-=1;
        }
        for(int j=1;j<=m;j++){
            //cout<<2*(h[j]+r[j]-l[j]+1)<<" ";
            ds=max(ds,2*(h[j]+r[j]-l[j]+1));
        }
        //cout<<"\n";
    }
    cout<<ds;
    return 0;
}

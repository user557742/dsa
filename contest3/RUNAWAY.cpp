
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
typedef long long ll;
int n;
ll a[maxn];
struct E{
    int u,v;
    ll x;
}e[maxn];
int id=0;
int pos[maxn];
int bd[maxn],kt[maxn];
vector<int> adj[maxn];
ll d[maxn];
void dfs(int u,int dad){
    pos[u]=++id;
    bd[u]=id;
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        ll x=e[i].x;
        if(v!=dad){
            d[v]=d[u]+x;
            dfs(v,u);
        }
    }
    kt[u]=id;
}
ll smax[20][maxn];
ll smin[20][maxn];
void build(){
    for(int i=1;i<=n;i++){
        smax[0][i]=a[i];
        smin[0][i]=a[i];
    }
    int k=__lg(n);
    for(int i=1;i<=k;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            smax[i][j]=max(smax[i-1][j],smax[i-1][j+(1<<(i-1))]);
            smin[i][j]=min(smin[i-1][j],smin[i-1][j+(1<<(i-1))]);
        }
    }
}
ll getmax(int u,int v){
    int i=__lg(v-u+1);
    return max(smax[i][u],smax[i][v-(1<<i)+1]);
}
ll getmin(int u,int v){
    int i=__lg(v-u+1);
    return min(smin[i][u],smin[i][v-(1<<i)+1]);
}
int calca(int u,int v,ll x){
    if(u>v) return 0;
    if(u==v) return a[u]<=x;
    if(getmax(u,v)<=x) return v-u+1;
    int mid=(u+v)/2;
    int ds=0;
    if(getmin(u,mid )<=x) ds+=calca(u,mid,x);
    if(getmin(mid+1,v)<=x) ds+=calca(mid+1,v,x);
    return ds;
}
int calc(int u,int v,ll x){
    int ds=0;
    for(int i=u;i<=v;i++) if(a[i]<=x) ds++;
    return ds;
}
ll l;
void sub1(){
    for(int i=1;i<=n;i++) cout<<calc(bd[i],kt[i],l+d[i])<<"\n";
}
void sub2(){
    build();
    for(int i=1;i<=n;i++) cout<<calca(bd[i],kt[i],l+d[i])<<"\n";
}
int main(){
    if(fopen("RUNAWAY.INP","r")){
        freopen("RUNAWAY.INP","r",stdin);
        freopen("RUNAWAY.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>l;
    for(int i=1;i<n;i++){
        cin>>e[i].u>>e[i].x;
        e[i].v=i+1;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) a[bd[i]]=d[i];
    if(n<=1000) sub1();
    else sub2();
}
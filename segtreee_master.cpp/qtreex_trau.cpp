#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,q;
struct E{
    int u=0,v=0,l=0;
    E(int _u=0,int _v=0,int _l=0):u(_u),v(_v),l(_l) {}
}e[maxn];
vector<int> adj[maxn];
int pre[maxn],depth[maxn];
void dfs(int u,int dad){
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        if(v!=dad){
            pre[v]=i;
            depth[v]=depth[u]+1;
            dfs(v,u);
        }
    }
}
void change(){
    int k,x;cin>>k>>x;
    e[k].l=x;
}
void neg(){
    int u,v;cin>>u>>v;
    if(depth[u]>depth[v]) swap(u,v);
    while(depth[v]>depth[u]){
        int i=pre[v];
        int nv=(e[i].v==v) ? e[i].u:e[i].v;
        e[i].l*=-1;
        v=nv;
    }
    while(u!=v){
        int i=pre[v];
        int nv=(e[i].v==v) ? e[i].u:e[i].v;
        e[i].l*=-1;
        v=nv;
        int j=pre[u];
        int nu=(e[j].u==u) ? e[j].v:e[j].u;
        e[j].l*=-1;
        u=nu;
    }
}
void query(){
    int u,v;cin>>u>>v;
    if(depth[u]>depth[v]) swap(u,v);
    int ds=INT_MIN;
    while(depth[v]>depth[u]){
        int i=pre[v];
        int nv=(e[i].v==v) ? e[i].u:e[i].v;
        ds=max(ds,e[i].l);
        v=nv;
    }
    while(u!=v){
        int i=pre[v];
        int nv=(e[i].v==v) ? e[i].u:e[i].v;
        ds=max(ds,e[i].l);
        v=nv;
        int j=pre[u];
        int nu=(e[j].u==u) ? e[j].v:e[j].u;
        ds=max(ds,e[j].l);
        u=nu;
    }
    cout<<ds<<"\n";
}
int main(){
    if(fopen("qtreex.inp","r")){
        freopen("qtreex.inp","r",stdin);
        freopen("qtreex.ans","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<n;i++){
        cin>>e[i].u>>e[i].v>>e[i].l;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    dfs(1,0);
    while(q--){
        string l;cin>>l;
        if(l=="CHANGE") change();
        if(l=="NEGATE") neg();
        if(l=="QUERY") query();
     }
}

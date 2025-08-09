#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,m;
vector<int> adj[maxn];
struct E{
    int u,v;
    E(int _u=0,int _v=0) : u(_u),v(_v){}
}e[maxn];
int low[maxn],num[maxn];
int id=0;
bool cau[maxn];
void dfs(int u,int dad){
    low[u]=num[u]=++id;
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        if(v!=dad){
            if(!num[v]){
                dfs(v,u);
                low[u]=min(low[u],low[v]);
                if(low[v]==num[v]) cau[i]=1;
            }else low[u]=min(low[u],num[v]);
        }

    }
}
vector<int> ke[maxn];
int slt[maxn];
int cl[maxn];
int val=0;
void calc(int u,int dad){
    slt[u]=val;
    cl[u]=1;
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        if(v!=dad&&cl[v]==0&&cau[i]==0){
            calc(v,u);
        }
    }
}
int d[maxn];
int pre[maxn];
int vs[maxn];
void tt(int u){
    vs[u]=1;
    for(int i:ke[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        v=slt[v];
        if(!vs[v]){
            pre[v]=i;
            tt(v);
            d[u]+=d[v];
        }
    }
}
int ds[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v;
    }
    for(int i=1;i<=m;i++){
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    for(int i=1;i<=n;i++) if(!num[i]) dfs(i,0);
    for(int i=1;i<=n;i++) if(cl[i]==0){
        ++val;
        calc(i,0);
    }
    for(int i=1;i<=m;i++){
        if(cau[i]){
            int u=slt[e[i].u],v=slt[e[i].v];
            ke[u].push_back(i);
            ke[v].push_back(i);
        }
    }
    int q;cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        u=slt[u];
        v=slt[v];
        d[u]++;
        d[v]--;
    }
    for(int i=1;i<=val;i++) if(!vs[i]) tt(i);
    for(int v=1;v<=val;v++){
        int i=pre[v];
        int u=(e[i].v==v) ? e[i].u : e[i].v;
        if(d[v]<0){
            if(u==e[i].u) ds[i]=1;
            else ds[i]=-1;
        }
        else {
            if(u==e[i].u) ds[i]=-1;
            else ds[i]=1;
        }
    }
    for(int i=1;i<=m;i++) {
        if(ds[i]==0) cout<<"B";
        if(ds[i]==1) cout<<"R";
        if(ds[i]==-1) cout<<"L";
    }
    return 0;
}

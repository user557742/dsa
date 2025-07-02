#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,k;
vector<int> adj[maxn];
int tsz=0,sz[maxn],pre[maxn];
int depth[maxn],con[maxn];
pair<int,int> st[19][maxn];
int pos[maxn],id=0;
void tt(int u,int dad){
    tsz++;
    sz[u]=1;
    for(int v:adj[u]) if(v!=dad){
        tt(v,u);
        sz[u]+=sz[v];
    }
}
int timc(int u,int dad){
    for(int v:adj[u]) if(v!=dad&&!pre[v]&&sz[v]>tsz/2) return timc(v,u);
    return u;   
}
void phanra(int u,int dad){
    tsz=0;
    tt(u,dad);
    int c=timc(u,dad);
    if(dad==0) pre[c]=c;
    else{
        pre[c]=dad;
        con[dad]=c; 
    }
    for(int v:adj[c]) if(!pre[v]) phanra(v,c);
}
void dfs(int u,int dad){
    pos[u]=++id;
    st[0][id]={depth[u],u};
    for(int v:adj[u]) if(v!=dad){
        depth[v]=depth[u]+1;
        dfs(v,u);
        st[0][++id]={depth[u],u};
    }
}
void build(){
    int k=__lg(id);
    for(int i=1;i<=k;i++){
        for(int j=1;j+(1<<i)-1<=id;j++) st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]); 
    }
}
int lca(int u,int v){
    int l=pos[u],r=pos[v];
    if(l>r) swap(l,r);
    int i=__lg(r-l+1);
    return min(st[i][l],st[i][r-(1<<i)+1]).second;
}
int dis(int u,int v){
    return depth[u]+depth[v]-depth[lca(u,v)];
}
vector<int> d[maxn],p[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
    }
    phanra(1,0);
    dfs(1,0);
    build();
    for(int i=1;i<=n;i++) if(con[i]==0) con[i]=i; 
    for(int u=1;u<=n;u++){
        p[u].push_back(0);
        int v=u;
        while(v!=con[v]){
            p[u].push_back(dis(u,v));
            v=con[v];
        }
        v=u;
        d[u].push_back(0);
        while(v!=pre[v]){
            d[v].push_back(dis(v,u));
            v=pre[v];
        }
    }
    for(int i=1;i<=n;i++){
        sort(d[i].begin(),d[i].end());
        sort(p[i].begin(),p[i].end());
    }
    int ds=0;
    for (int u = 1; u <= n; ++u) {
        ds += upper_bound(d[u].begin(), d[u].end(), k) - lower_bound(d[u].begin(), d[u].end(), k);
    }
    for (int u = 1; u <= n; ++u) {
        int v = u;
        while (v != pre[v]) {
            int x = k - dis(u, v);
            int w = pre[v];
            int cnt_all = upper_bound(d[w].begin(), d[w].end(), x) - lower_bound(d[w].begin(), d[w].end(), x);
            int cnt_same_subtree = upper_bound(p[w].begin(), p[w].end(), x) - lower_bound(p[w].begin(), p[w].end(), x);
            ds += cnt_all - cnt_same_subtree;
            v = pre[v];
        }
    }
    cout << ds / 2;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,m;
struct E{
    int u,v,l;
    E(int _u=0,int _v=0,int _l=0) : u(_u),v(_v),l(_l) {}
}e[maxn];
int pre[maxn];
int depth[maxn];
vector<int> adj[maxn];
pair<int,int> rmq[21][2*maxn];
int id=0,pos[maxn];
void dfs(int u,int dad){
    pos[u]=++id;
    rmq[0][id]={depth[u],u};

    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        if(v!=dad){
            depth[v]=depth[u]+1;
            pre[v]=i;
            dfs(v,u);
        }
        rmq[0][++id]={depth[u],u};
    }
}
void sub1(){
    int s,t,h;cin>>s>>t>>h;
    vector<int> l;
    if(depth[s]>depth[t]) swap(s,t);
    while(depth[t]>depth[s]){
        int i=pre[t];
        l.push_back(e[i].l);
        t=(e[i].v==t) ? e[i].u : e[i].v;
    }
    while(t!=s){
        int i=pre[t];
        l.push_back(e[i].l);
        t=(e[i].v==t) ? e[i].u : e[i].v;
        i=pre[s];
        l.push_back(e[i].l);
        s=(e[i].v==s) ? e[i].u : e[i].v;
    }
    sort(l.begin(),l.end());
    /*for(int x:l) cout<<x<<" ";
    cout<<"! ";*/
    int j=0;
    int ss=0;
    bool ok=0;
    for(int i=0;i<(int)l.size();i++){
        if(ss+l[i]>h){
            ok=1;
            j=i;
            break;
        }
        ss+=l[i];
    }
    if(ok) cout<< (int)l.size()-j<<"\n";
    else cout<<"0\n";
}
void build(){
    int k=__lg(id);
    for(int i=1;i<=k;i++){
        for(int j=1;j+(1<<(i))<=id+1;j++){
            rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
        }
    }
}
int lca(int u,int v){
    int l=pos[u],r=pos[v];
    if(l>r) swap(l,r);
    int i=__lg(r-l+1);
    return min(rmq[i][l],rmq[i][r-(1<<i)+1]).second;
}
void sub2(){
    int s,t,h;cin>>s>>t>>h;
    int w=lca(s,t);
    int d=depth[s]+depth[t]-2*depth[w];
    if(d<=h) cout<<"0\n";
    else cout<<d-h<<"\n";
}
int main(){
    if(fopen("TOURIST.INP","r")){
        freopen("TOURIST.INP","r",stdin);
        freopen("TOURIST.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int ok=1;
    for(int i=1;i<n;i++){
        cin>>e[i].u>>e[i].v>>e[i].l;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
        if(e[i].l!=1) ok=0;
    }
    dfs(1,0);
    if(ok) build();
    while(m--){
        if(ok) sub2();
        else sub1();
    }
    return 0;
}

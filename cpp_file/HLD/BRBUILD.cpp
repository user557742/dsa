#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n;vector<int> adj[maxn];
int depth[maxn],head[maxn],heavy[maxn];
int sz[maxn],pos[maxn],id=0,pre[maxn];
struct it{
    int s[4*maxn];
    void upd(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    int get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
} t;
void dfs(int u,int dad){
    pre[u]=dad;
    sz[u]=1;
    heavy[u]=-1;
    int cm=-1;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        sz[u]+=sz[v];
        if(cm<sz[v]){
            cm=sz[v];
            heavy[u]=v;
        }
    }
}
void hld(int u,int h){
    head[u]=h;
    pos[u]=++id;
    if(u!=h) depth[u]=depth[h];
    else depth[u]=depth[pre[u]]+1;
    if(heavy[u]!=-1) dfs(heavy[u],h);
    for(int v:adj[u]) if(v!=pre[u]&&v!=head[u]) hld(v,v);
}
void truyvan1(){
    int u,v;cin>>u>>v;
    if(pos[u]>pos[v]) swap(u,v);
    t.upd(pos[v],1);
}
void truyvan2(){
    int u;cin>>u;
    int v=1;
    int ds=0;
    if(depth[head[u]]> depth[head[v]] ) swap(u,v);
    while(depth[head[u]]!=depth[head[v]]){
        ds+=t.get(pos[head[v]],pos[v]);
        v=pre[head[v]];
    }
    while(head[u]!=head[v]){
        ds+=t.get(pos[head[u]],pos[u]);
        ds+=t.get(pos[head[v]],pos[v]);
        v=pre[head[v]];
        u=pre[head[u]];
    }
    if(pos[u]>pos[v]) swap(u,v);
    ds+=t.get(pos[u],pos[v]);
    cout<<ds<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie();
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;cin>>q;
    while(q--){
        char loai;cin>>loai;
        if(loai=='A') truyvan1();
        else truyvan2();
    }
}

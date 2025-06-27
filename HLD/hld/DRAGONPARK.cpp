#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,a[maxn];vector<int> adj[maxn];
int depth[maxn],head[maxn],heavy[maxn];
int pos[maxn],pre[maxn],sz[maxn],id=0;
typedef long long ll;
struct it{
    ll s[4*maxn];
    void upd(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]^s[2*r+1];
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        ll L=getans(u,v,2*r,lo,mid);
        ll R=getans(u,v, 2*r+1,mid+1,hi);
        return (L^R);
    }
}t;
/*
struct itfake{
    int s[maxn];
    void upd(int k,int x){
        s[k]=x;
    }
    int getans(int u,int v){
        int ds=0;
        for(int i=u;i<=v;i++) ds^=s[i];
        return ds;
    }
} t;*/
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
    if(heavy[u]!=-1) hld(heavy[u],h);
    for(int v:adj[u]) if(v!=pre[u]&&v!=heavy[u]) hld(v,v);
}
void truyvan1(){
    int k,x;cin>>k>>x;
    t.upd(pos[k],x);
}
void truyvan2(){
    int u,v;cin>>u>>v;
    ll ds=0;
    //if(depth[head[u]]>depth[head[v]]) swap(u,v);
    while(head[u]!=head[v]){
        if(depth[head[u]]>depth[head[v]]){
            ds^=t.getans(pos[head[u]],pos[u]);
            u=pre[head[u]];
        }
        else{
            ds^=t.getans(pos[head[v]],pos[v]);
            v=pre[head[v]];
        }
    }
    if(pos[u]>pos[v]) swap(u,v);
    ds^=t.getans(pos[u],pos[v]);
    cout<<ds<<"\n";
}
int q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    //for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    hld(1,1);
    for(int i=1;i<=n;i++) cout<<heavy[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<head[i]<<" ";
    cout<<"\n";
    /*for(int i=1;i<=n;i++) t.upd(pos[i],a[i]);
    while(q--){
        int loai;cin>>loai;
        if(loai==1) truyvan1();
        else truyvan2();
    }*/
}

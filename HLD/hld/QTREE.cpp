#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n;vector<int> adj[maxn];
int depth[maxn],head[maxn],heavy[maxn];
int pre[maxn],pos[maxn],sz[maxn],id=0;
int idx[maxn];
struct it{
    int s[4*maxn];
    void upd(int k,int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=1-s[r];
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,2*r,lo,mid);
        else upd(k,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    int get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>v) return 0;
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
    int cnt(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo||s[r]==0) return 1e9;
        if(lo==hi) return lo;
        int mid=(lo+hi)/2;
        int L=cnt(u,v,2*r,lo,mid);
        if(L!=1e9) return L;
        return cnt(u,v,2*r+1,mid+1,hi);
    }
}t;
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
    idx[id]=u;
    if(u!=h) depth[u]=depth[h];
    else depth[u]=depth[pre[u]]+1;
    if(heavy[u]!=-1) hld(heavy[u],h);
    for(int v:adj[u]) if(v!=pre[u]&&v!=heavy[u]) hld(v,v);
}
void truyvan1(){
    int k;cin>>k;
    t.upd(pos[k]);
}
void truyvan2(){
    int u,v=1;cin>>u;
    int ds=1e9;
    while(head[u]!=head[v]){
        if(depth[head[u]]>depth[head[v]]){
            ds=min(ds,t.cnt(pos[head[u]],pos[u]));
            u=pre[head[u]];
        }
        else{
            ds=min(ds,t.cnt(pos[head[v]],pos[v]));
            v=pre[head[v]];
        }
    }
    if(pos[u]>pos[v]) swap(u,v);
    ds=min(ds,t.cnt(pos[u],pos[v]));
    if(ds==1e9) cout<<"-1\n";
    else cout<<idx[ds]<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    hld(1,1);
    while(q--){
        int loai;cin>>loai;
        if(loai==0) truyvan1();
        else truyvan2();
    }
}

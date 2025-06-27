#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
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
        s[r]=s[2*r]+s[2*r+1];
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return getans(u,v,2*r,lo,mid)+getans(u,v,2*r+1,mid+1,hi);
    }
}t;
vector<int> adj[maxn];
int pre[maxn],depth[maxn],sz[maxn];
int heavy[maxn],head[maxn],st[maxn];
int id=0;
void dfs(int u,int dad){
    pre[u]=dad;
    sz[u]=1;
    int cm=-1;
    st[u]=++id;
    for(int v:adj[u]) if(v!=dad){
        depth[v]=depth[u]+1;
        dfs(v);
        sz[u]+=sz[v];
        if(cm<sz[v]){
            cm=sz[v];
            heavy[u]=v;
        }
    }
}
void HLD(int u,int head_u){
    head[u]=head_u;
    if(heavy[u]!=0) HLD(heavy[u],head_u);
}
int main(){

}

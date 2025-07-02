
#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
const int maxn = 1e6+1;
const int oo=1e9+5;
typedef long long ll;
int n;vector<int> adj[maxn];
struct E{
    int u=0,v=0,l=0;
    E(int _u=0,int _v=0,int _l=0):u(_u),v(_v),l(_l){}
}e[maxn];
int depth[maxn],head[maxn],heavy[maxn];
int pos[maxn],pre[maxn],id=0,sz[maxn];
struct node{
    int smin=oo,smax=-oo,dau=1;
    node(int _smin=oo,int _smax=-oo,int _dau=1):smin(_smin),smax(_smax),dau(_dau){}
};
node com(node u,node v){
    return node(min(u.smin,v.smin),max(u.smax,v.smax),1);
}
struct segtree{
    node g[4*maxn];
    void pull(int r){
        g[r]=com(g[2*r],g[2*r+1]);
    }
    void apply(int x,int r,int lo,int hi){
        g[r].dau*=x;
        g[r].smax*=x;
        g[r].smin*=x;
        if(g[r].smax<g[r].smin) swap(g[r].smax,g[r].smin);
    }
    void push(int r,int lo,int hi){
        if(g[r].dau==1) return ;
        int mid=(lo+hi)/2;
        apply(-1,2*r,lo,mid);
        apply(-1,2*r+1,mid+1,hi);
        g[r].dau=1;
    }
    void change(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi){
            g[r].smax=x;
            g[r].smin=x;
            g[r].dau=1;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) change(k,x,2*r,lo,mid);
        else change(k,x,2*r+1,mid+1,hi);
        pull(r);
    }
    void neg(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>v) return ;
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            apply(-1,r,lo,hi);
            return ;
        }
        int mid=(lo+hi)/2;
        push(r,lo,hi);
        neg(u,v,2*r,lo,mid);
        neg(u,v,2*r+1,mid+1,hi);
        pull(r);
    }
    node get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>v) return node(oo,-oo,1);
        if(u>hi||v<lo) return node(oo,-oo,1);
        if(u<=lo&&hi<=v) return g[r];
        int mid=(lo+hi)/2;
        push(r,lo,hi);
        node L=get(u,v,2*r,lo,mid);
        node R=get(u,v,2*r+1,mid+1,hi);
        return com(L,R);
    }
}t;
void dfs(int u,int dad){
    pre[u]=dad;
    heavy[u]=-1;sz[u]=1;
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
    int u;
    if(pos[e[k].u]<pos[e[k].v]) u=e[k].v;
    else u=e[k].u;
    t.change(pos[u],x);
}
void truyvan2(){
    int u,v;cin>>u>>v;
    if(depth[head[u]]>depth[head[v]]) swap(u,v);
    while(depth[head[u]]!=depth[head[v]]){
        t.neg(pos[head[v]],pos[v]);
        v=pre[head[v]];
    }
    while(head[u]!=head[v]){
        t.neg(pos[head[u]],pos[u]);
        t.neg(pos[head[v]],pos[v]);
        u=pre[head[u]];
        v=pre[head[v]];
    }
    if(pos[u]>pos[v]) swap(u,v);
    if(pos[u]<pos[v]) t.neg(pos[u]+1,pos[v]);
}
void truyvan3(){
    int u,v;cin>>u>>v;
    if(u==v){
        cout<<"0\n";
        return ;
    }
    int ds=-oo;
    if(depth[head[u]]>depth[head[v]]) swap(u,v);
    while(depth[head[u]]!=depth[head[v]]){
        ds=max(ds,t.get(pos[head[v]],pos[v]).smax);
        v=pre[head[v]];
    }
    while(head[u]!=head[v]){
        ds=max(ds,t.get(pos[head[v]],pos[v]).smax);
        ds=max(ds,t.get(pos[head[u]],pos[u]).smax);
        v=pre[head[v]];
        u=pre[head[u]];
    }
    if(pos[u]>pos[v]) swap(u,v);
    if(pos[u]<pos[v]) ds=max(ds,t.get(pos[u]+1,pos[v]).smax);
    cout<<ds<<"\n";
}int q;
int main(){
    if(fopen("qtreex.inp","r")){
        freopen("qtreex.inp","r",stdin);
        freopen("qtreex.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<n;i++) cin>>e[i].u>>e[i].v>>e[i].l;
    for(int i=1;i<n;i++){
        adj[e[i].u].push_back(e[i].v);
        adj[e[i].v].push_back(e[i].u);
    }
    dfs(1,0);
    hld(1,1);
    //t.change(1,-oo);
    for(int i=1;i<n;i++){
        if(pos[e[i].u]<pos[e[i].v]){
            t.change(pos[e[i].v],e[i].l);
        }else{
            t.change(pos[e[i].u],e[i].l);
        }
    }
    while(q--){
        string l;cin>>l;
        if(l=="CHANGE") truyvan1();
        if(l=="NEGATE") truyvan2();
        if(l=="QUERY") truyvan3();
     }
}

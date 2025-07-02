#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
typedef long long ll;
int n;ll a[maxn];
int gtbandau;
struct node{
    ll s=gtbandau,lz=gtbandau;
    node(ll _s=gtbandau,ll _lz=gtbandau) : s(_s),lz(_lz) {}

};
node com(node u,node v){
    node ds;
    return ds;
}
const node gg=node(0,0);
struct segtree{
    node g[4*maxn];
    void pull(int r){
        g[r]=com(g[2*r],g[2*r+1]);
    }
    void apply(ll x,int r=1,int lo=1,int hi=n){

    }
    void push(int r,int lo,int hi){

    }
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            apply(a[lo],r,lo,lo);
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        g[r]=com(g[2*r],g[2*r+1]);
    }
    void upd(int u,int v,ll x,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            apply(x,r,lo,hi);
            return ;
        }
        int mid=(lo+hi)/2;
        push(r,lo,hi);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,2*r+1,mid+1,hi);
        pull(r);
    }
    node get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return gg;
        if(u<=lo&&hi<=v) return g[r];
        int mid=(lo+hi)/2;
        push(r,lo,hi);
        node L=get(u,v,2*r,lo,mid);
        node R=get(u,v,2*r+1,mid+1,hi);
        return com(L,R);
    }
}t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    t.build();
    int q;cin>>q;
    while(q--){
        int loai;cin>>loai;
        if(loai==1){
            int u,v,x;cin>>u>>v>>x;
            t.upd(u,v,x);
        }
        else{
            int u,v;cin>>u>>v;
            cout<<t.get(u,v).s<<"\n";
        }
    }
}

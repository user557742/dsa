#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,a[maxn];
typedef long long ll;
struct node{
    ll s=0,lz=0;
    node(ll _s=0,ll _lz=0) : s(_s),lz(_lz) {}
};
node com(node u,node v){
    return node(max(u.s,v.s),0);
}
struct IT{
    node g[4*maxn];
    void pull(int r){
        g[r]=com(g[2*r],g[2*r+1]);
    }
    void apply(ll x,int r){
        g[r].s+=x;
        g[r].lz+=x;
    }
    void push(int r){
        if(g[r].lz==0) return ;
        apply(g[r].lz,2*r);
        apply(g[r].lz,2*r+1);
        g[r].lz=0;
    }
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            apply(a[lo],r);
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        pull(r);
    }
    void upd(int u,int v,ll x,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v) {
            apply(x,r);
            return ;
        }
        int mid=(lo+hi)/2;
        push(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        pull(r);
    }
    node get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return node(-1e18,0);
        if(u<=lo&&hi<=v) return g[r];
        int mid=(lo+hi)/2;
        push(r);
        node L=get(u,v,2*r,lo,mid);
        node R=get(u,v,2*r+1,mid+1,hi);
        return com(L,R);
    }
}t;
int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    t.build();
    int q;cin>>q;
    while(q--){
        int l;cin>>l;
        if(l==1){
            int u,v;ll x;cin>>u>>v>>x;
            t.upd(u,v,x);
        }
        else{
            int u,v;cin>>u>>v;
            cout<<t.get(u,v).s<<"\n";
        }
    }
}
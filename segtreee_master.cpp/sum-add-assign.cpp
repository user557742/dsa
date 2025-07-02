#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,a[maxn];
struct node{
    ll s=0,lz_add=0,lz_ass=0;
    bool hlz=0;
    node(ll _s=0,ll _lz_add=0,ll _lz_ass=0,bool _h=0) : s(_s),lz_add(_lz_add),lz_ass(_lz_ass),hlz(_h) {}
};
node com(node u,node v){
    return node(u.s+v.s,0,0,0);
}
struct it{
    node g[4*maxn];
    void pull(int r){
        g[r]=com(g[2*r],g[2*r+1]);
    }
    void apply1(ll x,int r,int lo,int hi){
        g[r].s=x*(hi-lo+1);
        g[r].lz_ass=x;
        g[r].hlz=1;
    }
    void apply2(ll x,int r,int lo,int hi){
        g[r].s+=x*(hi-lo+1);
        g[r].lz_add+=x;
    }
    void push1(int r,int lo,int hi){
        if(g[r].hlz==0) return ;
        int mid=(lo+hi)/2;
        apply1(g[r].lz_ass,2*r,lo,mid);
        apply1(g[r].lz_ass,2*r+1,mid+1,hi);
        g[r].hlz=0;
    }
    void push2(int r,int lo,int hi){
        if(g[r].lz_add==0) return;
        int mid=(lo+hi)/2;
        apply2(g[r].lz_add,2*r,lo,mid);
        apply2(g[r].lz_add,2*r+1,mid+1,hi);
        g[r].lz_add=0;
    }
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            g[r].s=a[lo];
            g[r].lz_add=0;
            g[r].lz_ass=0;
            g[r].hlz=0;
            return;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        pull(r);
    }
    void upd1(int u,int v,ll x,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            apply1(x,r,lo,hi);
            return ;
        }
        int mid=(lo+hi)/2;
        push1(r,lo,hi);
        upd1(u,v,x,2*r,lo,mid);
        upd1(u,v,x,2*r+1,mid+1,hi);
        pull(r);
    }
    void upd2(int u,int v,ll x,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            apply2(x,r,lo,hi);
            return ;
        }
        int mid=(lo+hi)/2;
        push2(r,lo,hi);
        upd2(u,v,x,2*r,lo,mid);
        upd2(u,v,x,2*r+1,mid+1,hi);
        pull(r);
    }
    ll get(int u,int v,int r=1)
};
int main(){

}

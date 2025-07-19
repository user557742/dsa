#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,a[maxn];
struct it{
    int smax[4*maxn],smin[4*maxn];
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            smax[r]=a[lo];
            smin[r]=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        smax[r]=max(smax[2*r],smax[2*r+1]);
        smin[r]=min(smin[2*r],smin[2*r+1]);
    }
    void upd(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi){
            smax[r]=x;
            smin[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        smax[r]=max(smax[2*r],smax[2*r+1]);
        smin[r]=min(smin[2*r],smin[2*r+1]);
    }
    int calc(int u,int v,int r=1,int lo=1,int hi=n){
        if(smax[r]<u) return 0;
        if(smin[r]>v) return 0;
        if(smax[r]<=v&&smin[r]>=u) return hi-lo+1;
        if(lo==hi) return (u<=smax[r])&&(smax[r]<=v);
        int mid=(lo+hi)/2;
        int ds=calc(u,v,2*r,lo,mid)+calc(u,v,2*r+1,mid+1,hi);
        return ds;
    }
}t;
int main(){
    if(fopen("SALARYQR.inp","r")){
        freopen("SALARYQR.inp","r",stdin);
        freopen("SALARYQR.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    t.build();
    while(q--){
        char l;cin>>l;
        if(l=='!'){
            int u,x;cin>>u>>x;
            t.upd(u,x);
        }
        else{
            int u,v;
            cin>>u>>v;
            cout<<t.calc(u,v)<<"\n";
        }
    }
}
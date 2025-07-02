#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n;
int a[maxn];
typedef long long ll;
struct it{
    ll smax[4*maxn];
    ll smin[4*maxn];
    void upd(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi) {
            smax[r]=x;
            smin[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        smin[r]=min(smin[2*r],smin[2*r+1]);
        smax[r]=max(smax[2*r],smax[2*r+1]);
    }
    ll getmin(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return INT_MAX;
        if(u<=lo&&hi<=v) return smin[r];
        int mid=(lo+hi)/2;
        return min(getmin(u,v,2*r,lo,mid),getmin(u,v,2*r+1,mid+1,hi));
    }
    ll getmax(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return INT_MIN;
        if(u<=lo&&hi<=v) return smax[r];
        int mid=(lo+hi)/2;
        return max(getmax(u,v,2*r,lo,mid),getmax(u,v,2*r+1,mid+1,hi));
    }
    int calc(int u,int v,ll x){
        if(u>v) return 0;
        if(u==v) return a[u]<=x;
        if(getmax(u,v)<=x) return v-u+1;
        int mid=(u+v)/2;
        int ds=0;
        if(getmin(u,mid )<=x) ds+=calc(u,mid,x);
        if(getmin(mid+1,v)<=x) ds+=calc(mid+1,v,x);
        return ds;
    }
}st;
int main(){
    if(fopen("tmp.in","r")){
        freopen("tmp.in","r",stdin);
        freopen("tmp.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) st.upd(i,a[i]);
    int q;cin>>q;
    while(q--){
        int u,v,x;cin>>u>>v>>x;
        cout<<st.calc(u,v,x)<<"\n";
    }
}
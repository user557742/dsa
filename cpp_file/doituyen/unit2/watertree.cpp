#include <bits/stdc++.h>
using namespace std;
const int maxn= 5e5+1;
typedef long long ll;
int bd[maxn],kt[maxn],pos[maxn];
int n,m;int id=0;
int pre[maxn];
vector <int> adj[maxn];
void dfs(int u,int dad){
    id++;
    bd[u]=id;
    pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        pre[v]=u;
        dfs(v,u);
    }
    kt[u]=id;
}
struct ST{
    ll s[4*maxn+1];
    int nho[4*maxn+1];
    ll lz[4*maxn+1];
    void down(int r){
        if(nho[r]){
            lz[2*r]=lz[2*r+1]=lz[r];
            nho[2*r]=nho[2*r+1]=1;
            nho[r]=0;
        }
    }
    void up(int r){
        ll t1=(nho[2*r]) ? lz[2*r] : s[2*r];
        ll t2=(nho[2*r+1]) ? lz[2*r+1] : s[2*r+1];
        s[r]=min(t1,t2);
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v) {
            nho[r]=1;
            lz[r]=x;
            return ;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        up(r);
    }
    ll get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 1e18;
        if(u<=lo&&hi<=v) return (nho[r]) ? lz[r] : s[r];
        int mid=(lo+hi)/2;
        down(r);
        ll L=get(u,v,2*r,lo,mid);
        ll R=get(u,v,2*r+1,mid+1,hi);
        up(r);
        return min(L,R);
    }


}st;

void truyvan1(){
    int u;cin>>u;

    st.upd(bd[u],kt[u],1);
}
void truyvan2(){
    int u;cin>>u;
    st.upd(bd[u],bd[u],0);
}
void truyvan3(){
    int u;cin>>u;
    cout<<st.get(bd[u],kt[u])<< "\n";
}
int  main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cin>>m;
    while(m--){
        int loai;
        cin>>loai;
        if(loai==1) truyvan1();
        if(loai==2) truyvan2();
        if(loai==3) truyvan3();
    }
}


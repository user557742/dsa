// ép cây thành mảng
// dùng segment tree để thực hiện truy vấn
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5*1e5+1;
#define int long long
int a[maxn];
int bd[maxn];
int pos[maxn];
int kt[maxn];
int sz=0;
typedef long long ll;
struct IT{
    vector<ll> s,lz;
    void init(int _sz=0){
        s.resize(4*_sz+1,0);
        lz.resize(4*_sz+1,0);
        sz=_sz;
    }
    void build(int r=1,int lo=1,int hi=sz){
        if(lo==hi){
            s[r]=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    void down(int r){
        lz[2*r]+=lz[r];
        lz[2*r+1]+=lz[r];
        lz[r]=0;
    }
    void upd(int u,int v,int d,int r=1,int lo=1,int hi=sz){
        if(u>hi||lo>v) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=d;
            return; 
        }
        int mid=(lo+hi)/2;
        down(r);
 
        upd(u,v,d,2*r,lo,mid);
        upd(u,v,d,2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=sz){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r]+(hi-lo+1)*lz[r];
        int mid=(lo+hi)/2;
        down(r);
        ll L=getans(u,v,2*r,lo,mid);
        ll R=getans(u,v,2*r+1,mid+1,hi);
        
        s[r]=s[2*r+1]+s[2*r]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
        return R+L;
    }
}ST;
vector<int> adj[maxn];

int id=0,n,m;
void dfs(int u,int dad){
    id++;
    bd[u]=id;
    pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    kt[u]=id;
}
void truyvan1(int u,int x){
    if(bd[u]==kt[u]) return ;
    ST.upd(bd[u]+1,kt[u],x);
}
void truyvan2(int u){
    cout<<ST.getans(bd[u],bd[u]) <<"\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++) {
        int j;cin>>a[i]>>j;
        adj[j].push_back(i);
        adj[i].push_back(j);
    }
    dfs(1,0);
    ST.init(id);
    ST.build();
    while(m--){
        char loai;cin>>loai;
        if(loai=='p'){
            int u,x;cin>>u>>x;
            truyvan1(u,x);
        }
        else{
            int u;cin>>u;
            truyvan2(u);
        }
    }
}
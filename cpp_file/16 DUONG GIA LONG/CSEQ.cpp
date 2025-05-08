#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n,q;
int a[maxn];
struct IT{
    vector<ll> s,lz,g;
    void init(){
        s.resize(4*n+1,0);
        lz.resize(4*n+1,0);
        g.resize(4*n+1,0);
    }  
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=a[lo];
            g[r]=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r+1]+s[2*r];
        g[r]=min(g[2*r],g[2*r+1]);
    }
    void down(int r){
        lz[2*r]+=lz[r];
        lz[2*r+1]+=lz[r];
        lz[r]=0;
    }
    void up(int r,int lo,int hi){
        int mid=(lo+hi)/2;
        s[r]=s[2*r]+s[2*r+1]+lz[2*r]*(mid-lo+1)+lz[2*r+1]*(hi-mid);
        g[r]=min(g[2*r]+lz[2*r],g[2*r+1]+lz[2*r+1]);
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            lz[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        up(r,lo,hi);
    }
    ll getg(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return 1e18;
        if(u<=lo&&hi<=v) {
            return g[r]+lz[r];
        }
        int mid=(lo+hi)/2;
        down(r);
        ll L=getg(u,v,2*r,lo,mid);
        ll R=getg(u,v,2*r+1,mid+1,hi);
        up(r,lo,hi);
        return min(L,R);
    }
    ll gets(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) {
            return s[r]+lz[r]*(hi-lo+1);
        }
        int mid=(lo+hi)/2;
        down(r);
        ll L=gets(u,v,2*r,lo,mid);
        ll R=gets(u,v,2*r+1,mid+1,hi);
        up(r,lo,hi);
        return L+R;
    }
}st;
void truyvanP(){
    int u,v,x;cin>>u>>v>>x;
    st.upd(u,v,x);
}
void truyvanM(){
    int u,v;cin>>u>>v;
    cout<<st.getg(u,v)<<"\n";
}
void truyvanS(){
    int u,v;cin>>u>>v;
    cout<<st.gets(u,v)<<"\n";
}
int main(){
    if(fopen("CSEQ.INP","r")){
        freopen("CSEQ.INP","r",stdin);
        freopen("CSEQ.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    rei(i,1,n) cin>>a[i];
    st.init();
    st.build();
    while(q--){
        char loai;cin>>loai;
        if(loai=='M') truyvanM();
        if(loai=='P') truyvanP();
        if(loai=='S') truyvanS();
    }

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
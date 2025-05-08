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
int n,sz,q;
ll a[maxn];
ll bl[maxn];
int getbl(int i){
    return i/sz;
}
ll getans(int l,int r){
    int u=getbl(l);
    int v=getbl(r);
    ll ds=1e18;
    if(u==v){
        rei(i,l,r) ds=min(ds,a[i]);
        return ds; 
    }
    rei(i,u+1,v-1) ds=min(ds,bl[i]);
    rei(i,l,sz*(u+1)-1) ds=min(ds,a[i]);
    rei(i,sz*v,r) ds=min(ds,a[i]);
    return ds;
}
void upd(int k,ll x){
    ll nbl=1e18;
    int u=getbl(k);
    a[k]=x;
    rei(i,sz*u,sz*(u+1)-1) nbl=min(nbl,a[i]);
    bl[u]=nbl;
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    sz=sqrt(n);
    rei(i,1,n) cin>>a[i];
    rei(i,1,n) bl[getbl(i)]=1e18;
    rei(i,1,n) bl[getbl(i)]=min(bl[getbl(i)],a[i]);
    while(q--){
        int l;cin>>l;
        if(l==1){
            int k,x;cin>>k>>x;
            upd(k,x);
        }
        else{
            int u,v;cin>>u>>v;
            cout<<getans(u,v)<<"\n";
        }
    }
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
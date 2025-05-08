// cho một cây n đỉnh và m quy tắc . ta cần định chiều của cây sao cho thỏa mãn mọi quy tắc
// đếm số cách định chiều
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
int n;
vector<int> adj[maxn];
int m;
pair<int,int> e[maxn];
void inp(){
    cin>>n>>m;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rei(i,1,m) cin>>e[i].X>>e[i].Y;
}
ll bpow(ll u,ll v){
    ll ds=1;
    while(v>0){
        if(v%2) ds=(ds*u)%mod;
        u=(u*u)%mod;
        v/=2;
    }
    return ds;
}
void sub1(){
    vector<pair<int,int>> gg;
    rei(i,1,m){
        gg.pb({e[i].X,0});
        gg.pb({e[i].Y,1});
    }
    sort(gg.begin(),gg.end());
    int cnt=0;
    int k=n-1;
    int l=0,r=0;
    int dem=0;
    int prev=0;
    for(pair<int,int> x:gg){
        if(x.X==prev) continue;
        if(x.Y==0){
            if(cnt==0){
                dem++;
                k-=r-l;
                l=x.X;
            }
            cnt++;
        } 
        else{
            if(cnt==1){
                r=x.X;
            }
            cnt--;
        }
        prev=x.X;
    }
    k-=r-l;
    cout<<bpow(2,dem+k);
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    inp();
    sub1();


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
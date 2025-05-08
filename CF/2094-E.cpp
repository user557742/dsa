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
ll a[maxn];
ll cnt[maxn];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
void solve(){
    ll ds=0;
    rei(i,1,30) cnt[i]=0;
    rei(j,1,n){
        rei(i,1,30) cnt[i]+=getbit(i,a[j]);
    }
    rei(k,1,n){
        ll ans=0;
        rei(i,1,30){
            int x=getbit(i,a[k]);
            if(x==1) ans+=(n-cnt[i])*(1<<(i-1));
            else ans+=cnt[i]*(1<<(i-1));
        }
        ds=max(ds,ans);
    }
    cout<<ds<<"\n";
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        rei(i,1,n) cin>>a[i];
        solve();
    }

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
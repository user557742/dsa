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
ll bpow(ll a, ll b) {
    __int128 res = 1, base = a;
    while (b > 0) {
        if (b & 1) res *= base;
        base *= base;
        b >>= 1;
    }
    return (ll)res;
}

ll f(ll x, ll y) {
    ll lo = 1, hi = min((ll)1e9+5, y);
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        __int128 temp = 1;
        for (int i = 0; i < x; ++i) {
            temp *= mid;
            if (temp > y) break;
        }
        if (temp == y) return mid;
        if (temp < y) lo = mid + 1;
        else hi = mid - 1;
    }
    return lo;
}

bool snt(ll n){
    for(ll i=2;i*i<=n;i++) if(n%i==0) return 0;
    return 1;
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;cin>>n;

    // log(2,10^18) = log(10,10^18)/log(10,2)=18/log(10,2)=18*log(2,10)=18+18log(2,5)
    // lim = 18+18*__lg(5)
    // p^x=n -> log(x,n) = p (1<=x<=lim) ->p=log(x,n)=__lg(n)/__lg(x) neu p la snt retrun ds;
    red(x,60,0){
        ll t=f(x,n);
        if(bpow(t,x)==n &&snt(t)){
            cout<<t<<" "<<x;
            return 0;
        }
    } 
    cout<<"0";
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
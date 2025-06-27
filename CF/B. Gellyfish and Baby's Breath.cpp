#include <iostream>
using namespace std;
const long long mod=998244353;
typedef long long ll;
ll bpow(ll a,ll b){
    ll ds=1;
    while(b>0){
        if(b%2) a=(a*ds)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ds;
}
const int maxn = 1e5+1;
#define rei(i,a,b) for(int i=a;i<=b;i++)
ll p[maxn],q[maxn];
void solve(){
    cin>>n;
    rei(i,0,n-1) cin>>p[i];
    rei(i,0,n-1) cin>>q[i];
    rei(i,0,n-1){
        ll ds=0;
        int 
        rei(j,0,i){
            int x=i-j;

        } 
    }
}
/*
2^a+2^b ss 2^c+2^d
neu 2^a(2^(b-a)-1) ss 2^c*(2^(d-c)-1)
neu a<c
------> 2^(b-a)-1 ss 2^(c-a)*(c^(d-c)-1)
*/
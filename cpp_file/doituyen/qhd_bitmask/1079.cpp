#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;
const int mod = 1e9+7;
typedef long long ll;
ll gt[N];
ll bpow(ll a,ll b){
    ll ds=1;
    while(b>0){
        if(b%2) ds=(ds*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ds;
}
ll c(ll k,ll n){
    ll ms=gt[k]*gt[n-k];
    ms %=mod;
    return (gt[n]*bpow(ms,mod-2))%mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    gt[0]=1;
    for(int i=1;i<N;i++) gt[i]=(gt[i-1]*i)%mod;
    while(n--){
        int a,b;cin>>a>>b;
        cout<<c(b,a)<<"\n";
    }
}
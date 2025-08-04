#include <bits/stdc++.h>
using namespace std;
const int maxn  = 5001;
const int mod= 1e9+7;
int n,m,k;
typedef long long ll;
ll b[maxn],c[maxn];
ll dp[maxn];
ll add(ll a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}
ll sub(ll a, ll b) {
    a -= b;
    if (a < 0) a += mod;
    return a;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    dp[0]=1;
    for(int i=1;i<=m;i++){
        int s=i+k;
        for(int j=0;j<=n;j++){
            int wo=dp[j];
            int ws=(j>=s?dp[j-s]:0);
            b[j]=sub(wo,ws);
        }
        for(int j=0;j<=n;j++){
            c[j]=b[j];
            if(j>=i) c[j]=add(c[j],c[j - i]);
        }
        for(int j=0;j<=n;j++) dp[j]=c[j];
    }
    cout<<dp[n];
    return 0;
}

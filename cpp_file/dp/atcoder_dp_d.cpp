#include <iostream>
using namespace std;
const int maxn=101;
const int lim=1e5+1;
int n;
int w[maxn],v[maxn];
long long dp[maxn][lim];
int gt;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>gt;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int j=0;j<=gt;j++){
        for(int i=1;i<=n;i++){
            dp[i][j]=dp[i-1][j];
            if(j>=w[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
        }

    }
    cout<<dp[n][gt];
}
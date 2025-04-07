#include <bits/stdc++.h>
using namespace std;
const int N = 21;
const int mod = 1e9+7;
int a[22][22];
int n;
long long dp[1<<21];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    dp[0]=1;
    for(int x=0;x<(1<<n);x++){
        for(int j=1;j<=n;j++) if(getbit(j,x)){
            int y=x&(~(1<<(j-1)));
            int i=__builtin_popcount(x);
            if(a[i][j]) dp[x]=(dp[x]+dp[y])%mod;
        }
    }
    cout<<dp[(1<<n)-1];
}
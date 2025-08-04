#include <bits/stdc++.h>
using namespace std;
int n,x;
int dp[101][10001];
int a[101];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j]);
            if(j>=a[i]*(n-i+1)) dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]*(n-i+1)]+1);
        }
    }
    cout<<dp[n][x];
}

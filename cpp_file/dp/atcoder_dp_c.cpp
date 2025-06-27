#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn =1e5+1;
int n,a[maxn],b[maxn],c[maxn],dp[maxn][3];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n) {
        cin>>a[i]>>b[i]>>c[i];
    }
    rei(i,1,n){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+c[i];
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
}
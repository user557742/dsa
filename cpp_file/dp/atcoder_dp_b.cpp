#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 1e5+1;
int n,k;
int a[maxn];
int dp[maxn];
int main(){
    cin>>n>>k;
    rei(i,1,n) cin>>a[i];
    dp[1]=0;
    rei(i,2,n){
        dp[i]=1e9;
        rei(j,1,k){
            if(i>j) dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);
        }
    }
    cout<<dp[n];
}
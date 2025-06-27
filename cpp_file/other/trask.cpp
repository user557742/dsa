/*
dp[x] so ruy bang it nhat de co the tao thanh do dai x
dp[x] = max(dp[x-a],dp[x-b],dp[x-c]) +1 ; 
*/
#include <iostream>
using namespace std;
const int maxn = 4001;
int dp[maxn];
int vis[maxn];
int n,a,b,c;
int main(){
    cin>>n>>a>>b>>c;
    vis[0]=1;
    for(int i=1;i<=n;i++){

        if(i>=a) vis[i]=max(vis[i],vis[i-a]);
        if(i>=b) vis[i]=max(vis[i],vis[i-b]);
        if(i>=c) vis[i]=max(vis[i],vis[i-c]);
        if(i>=a) if(vis[i-a]) dp[i]=max(dp[i],dp[i-a]+1);
        if(i>=b) if(vis[i-b]) dp[i]=max(dp[i],dp[i-b]+1);
        if(i>=c) if(vis[i-c]) dp[i]=max(dp[i],dp[i-c]+1);
        
    }
    cout<<dp[n];
}
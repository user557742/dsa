#include <bits/stdc++.h>
using namespace std;

const int N = 20;
vector<pair<int,long long>> dp[1<<N];
int n,x;
int w[N+1];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int x=0;x<(1<<n);x++) dp[x]={1e18,1e18};
    dp[0]={0,0};
    for(int i=1;i<=n;i++) dp[1<<(i-1)] = {1,w[i]};
    for(int x=0;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            int y=x|(1<<(i-1));
            long long nc=dp[x].second;
            if(dp[x].second+w[i]>x){
                nc=w[i];
                dp[y]={dp[x].first+1,nc};
            }
            else dp[y]={dp[x].first,dp[x].second+w[i]};
        }
    }
    cout<<dp[(1<<n)-1].first;
}
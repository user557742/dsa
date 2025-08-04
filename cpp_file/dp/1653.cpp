#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 21;
int n,m;
int a[maxn];
pair<ll,ll> dp[1<<20];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int x=0;x<(1<<n);x++) dp[x]={1e18,1e18};
    for(int i=1;i<=n;i++) if(a[i]<=m) dp[(1<<(i-1))]={1,a[i]};
    for(int x=0;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            int y=x|(1<<(i-1));
            if(dp[x].second+a[i]<=m) dp[y]=min(dp[y],{dp[x].first,dp[x].second+a[i]});
            if(dp[y].first>=dp[x].first+1){
                dp[y].first=dp[x].first+1;
                if(dp[y].second>dp[x].second) dp[y].second=dp[x].second;
            }
        }
    }
    cout<<dp[(1<<n)-1].first;
}

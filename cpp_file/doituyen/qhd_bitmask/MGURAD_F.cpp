#include <bits/stdc++.h>
using namespace std;
int n,H;
const int N = 20;
long long dp[1<<N];
int h[N],w[N],s[N];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
bool ok(int x,int j){
    vector<pair<int,int>> wh;
    for(int i=1;i<=n;i++) if(getbit(i,x)) wh.push_back({w[i],s[i]});
    sort(wh.begin(),wh.end());
    long long tw=w[j];
    for(int i=wh.size()-1;i>=0;i--){
        if(wh[i].second<tw) return 0;
        tw+=wh[i].first;
    }
    return 1;
    
}
int main(){
    cin>>n>>H;
    for(int i=1;i<=n;i++) cin>>h[i]>>w[i]>>s[i];
    dp[0]=0;
    for(int i=1;i<=n;i++) dp[1<<(i-1)]=h[i];
    for(int x=1;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            if(ok(x,i)){
                int y=x|(1<<(i-1));
                dp[y]=max(dp[y],dp[x]+h[i]);
            }
        }
    }
    long long ds=0;
    for(int x=0;x<(1<<n);x++) if(dp[x]>=H) ds=max(ds,1ll*__builtin_popcount(x));
    cout<<ds;
}
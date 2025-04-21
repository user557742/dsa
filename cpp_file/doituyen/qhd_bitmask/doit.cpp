#include <bits/stdc++.h>
using namespace std;
const int N = 21;
typedef long long ll;
int getbit(int x,int i){
    return (x>>(i-1))&1;
}
ll dp[1<<N];
int n,k;
int a[N][N];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int x=0;x<(1<<n);x++) dp[x]=1e18;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(i!=j) dp[1<<(i-1)]=min(1ll*a[i][j],dp[1<<(i-1)]);
    }
    for(int x=0;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(x,i)){
            for(int j=1;j<=n;j++) if(i!=j) if(!getbit(x,j)){
                int y=x|(1<<(i-1));
                dp[y]=min(dp[y],dp[x]+a[i][j]);
            }
        }
    }
    ll ds=1e18;
    for(int x=0;x<(1<<n);x++) if(n-__builtin_popcount(x)<=k) ds=min(ds,dp[x]);
    cout<<ds;
}
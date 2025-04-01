#include <bits/stdc++.h>
using namespace std;
const int N = 20;
const int oo = 1e9;
int s[N][N];
int dp[1<<N];
int n,k;
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>s[i][j];
    dp[0]=0;
    for(int x=1;x<(1<<n);x++) dp[x]=oo;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) if(i!=j) dp[1<<(i-1)]=min(dp[1<<(i-1)],s[i][j]);
    }
    for(int x=0;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            for(int j=1;j<=n;j++) if(i!=j) if(!getbit(j,x)){
                int y=x|(1<<(i-1));
                dp[y]=min(dp[x]+s[i][j],dp[y]);
            }
        }
    }
    int ds=oo;
    for(int x=0;x<(1<<n);x++){
        if(n-__builtin_popcount(x)<=k) ds=min(ds,dp[x]);
        
    }
    cout<<ds;  
    return 0;
}
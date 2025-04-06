#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=20;
int a[N+1][N+1];
int n,m;
long long dp[1<<N][21];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        a[u][v]+=1;
    }
    dp[1][1]=1;
    for(int x=0;x<(1<<n);x++) if(getbit(1,x)){
        for(int i=1;i<=n;i++) if(getbit(i,x)){
            for(int j=1;j<=n;j++) if((!getbit(j,x))&&a[i][j]>0){
                int y=x|(1<<(j-1));
                dp[y][j]=(dp[x][i]*a[i][j]+dp[y][j])%mod;
            }
        }
    } 
    cout<<dp[(1<<n)-1][n];
}
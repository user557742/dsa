#include<bits/stdc++.h>
using namespace std;
const int N = 21;
int n;
int a[N][N];
int dem[1<<N];
int dp[1<<N];
int getbit(int i,int x){
    return (x>>(i-1)) &1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    dem[0]=1;
    dp[0]=0;
    for(int x=0;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            int j=__builtin_popcount(x)+1;
            int y=x|(1<<(i-1));
            if(dp[x]+a[j][i]>dp[y]){
                dem[y]=dem[x];
                dp[y]=dp[x]+a[j][i];
            }
            else if(dp[x]+a[j][i]==dp[y]){
                dem[y]+=dem[x];
            } 
        }
    }
    cout<<dp[(1<<n)-1]<<" "<<dem[(1<<n)-1]; 
}
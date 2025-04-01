#include <bits/stdc++.h>
using namespace std;
const int oo=1e9;
const int N = 1<<(16);
int n;
int dp[N];
int s[16][16];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>s[i][j];
    dp[0]=0;
    for(int x=1;x<(1<<n);x++){
        dp[x]=oo;
        for(int i=1;i<=n;i++) if(getbit(i,x)){
            int y=x^(1<<(i-1));
            int gt=0;
            for(int j=1;j<=n;j++) if(getbit(j,y)) gt+=s[i][j];
            dp[x]=min(dp[x],dp[y]+gt+s[i][i]);
        }
    }
    cout<<dp[(1<<n)-1];
} 
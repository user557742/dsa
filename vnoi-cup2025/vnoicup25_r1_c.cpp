#include <iostream>
using namespace std;
const int maxn = 3e3+1;
string dp[maxn][maxn];
string s,t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=" "+s;
    t=" "+t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i]==t[j]){
                if(dp[i][j].size()<dp[i-1][j-1].size()+1){
                    dp[i][j]=dp[i-1][j-1];
                    dp[i][j].push_back(s[i]);
                }
            }
            if(dp[i][j].size()<dp[i-1][j].size()) dp[i][j]=dp[i-1][j];
            if(dp[i][j].size()<dp[i][j-1].size()) dp[i][j]=dp[i][j-1];
        }   
    }
    cout<<dp[n][m];
}
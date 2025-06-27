#include <iostream>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 1e3+1;
const int mod=1e9+7;
long long dp[maxn][maxn];
string s[maxn];
int n,m;
int main(){
    cin>>n>>m;
    rei(i,1,n) cin>>s[i];
    rei(i,1,n) s[i]=" "+s[i];
    rei(i,1,n){
        rei(j,1,m){
            dp[1][1]=1;
            if(s[i][j]=='#') dp[i][j]=0;
            else{
                long long t=0;
                if(s[i][j-1]!='#') t+=dp[i][j-1];
                if(s[i-1][j]!='#') t+=dp[i-1][j];
                dp[i][j]+=t%mod;
            }
        }
    }
    cout<<dp[n][m];
}
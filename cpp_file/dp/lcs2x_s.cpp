// tim day con chung dai nhat cua 2 day so A,B .
// do la day C phai tm c[i]*2<=c[i+1];
// dp[i][j] day lon dai nhat ket thuc o i ,j va a[i]==b[j]
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1501;
int n,m;
int a[maxn],b[maxn];
int dp[maxn][maxn];
#define rei(i,a,b) for(int i=a;i<=b;i++)
void solve(){
    cin>>n>>m;
    rei(i,1,n) cin>>a[i];
    rei(i,1,m) cin>>b[i];
    rei(i,1,n) rei(j,1,m) dp[i][j]=0;
    rei(i,1,n){
        rei(j,1,m) if(a[i]==b[j]){
            dp[i][j]=1;
            rei(u,1,i-1){
                rei(v,1,j-1){
                    if(a[u]==b[v]&&a[i]>=2*a[u]) dp[i][j]=max(dp[i][j],dp[u][v]+1);
                }
            }
        }
    }
    int ds=0;
    rei(i,1,n) rei(j,1,m) ds=max(ds,dp[i][j]);
    cout<<ds<<"\n";
}
int main(){
    if(fopen("in.inp","r")){
        freopen("in.inp","r",stdin);
        freopen("out.ans","w",stdout);
    }
    int t;cin>>t;
    while(t--) solve();
}

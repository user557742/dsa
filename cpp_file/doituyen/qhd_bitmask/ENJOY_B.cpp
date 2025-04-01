#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =20;
int n,m,k;
ll p[maxn];
ll a[maxn][maxn];
ll dp[1<<18][19];
int getbit(int k,int x){
    return (x>>(k-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>p[i];
    while(k--){
        int x,y,c;
        cin>>x>>y>>c;
        a[x][y]=c;
    }
    for(int i=1;i<=n;i++) dp[1<<(i-1)][i]=p[i];
    for(int x=0;x<(1<<n);x++) if(__builtin_popcount(x)<=m){
        for(int i=1;i<=n;i++) if(getbit(i,x)){
            for(int j=1;j<=n;j++) if(!getbit(j,x)) if(__builtin_popcount(x)<m){
                int y=x|(1<<(j-1));
                dp[y][j]=max(dp[y][j],dp[x][i]+a[i][j]+p[j]);
            }
        }
    }
    ll ds=0;
    for(int x=1;x<(1<<n);x++) if(__builtin_popcount(x)){
        for(int i=1;i<=n;i++) ds=max(ds,dp[x][i]);
    }
    cout<<ds;
    return 0;
}

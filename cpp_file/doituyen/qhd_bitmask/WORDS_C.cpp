#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =17;
string a[maxn];
int n;
ll dp[1<<17][18];
ll getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    
    for(int i=1;i<=n;i++) dp[1<<(i-1)][i]=a[i].size();
    for(int x=1;x<(1<<n);x++){
        if(__builtin_popcount(x)==1) continue; 
        for(int i=1;i<=n;i++) if(getbit(i,x)){
            int y=x&(~(1<<(i-1)));
            for(int j=1;j<=n;j++) if(getbit(j,y)){
                if(a[j][a[j].size()-1]==a[i][0]) dp[x][i]=max(dp[x][i],dp[y][j]+(int)a[i].size());
            }
        }
    }
    ll ds=0;
    for(int x=0;x<(1<<n);x++) for(int i=1;i<=n;i++) ds=max(ds,dp[x][i]);
    cout<<ds;
    return 0;
}
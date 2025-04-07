#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
int n,p,k;
struct nguoi{
    int aa;
    vector<int> ss;
} mp[N]; 
int s[N][8];
ll dp[N][1<<7];
int a[N];
bool cmp(nguoi a,nguoi b){
    return a.aa>b.aa;
}
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p>>k;
    for(int i=1;i<=n;i++) cin>>mp[i].aa;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=p;j++){
            int x;cin>>x;
            mp[i].ss.push_back(x);
        }
    }
    sort(mp+1,mp+n+1,cmp);
    for(int i=1;i<=n;i++) a[i]=mp[i].aa;
    for(int i=1;i<=n;i++){
        for(int j=0;j<p;j++){
            s[i][j+1]=mp[i].ss[j];
        }
    }
    for(int x=0;x<(1<<p);x++) dp[0][x]=-1e18;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int x=0;x<(1<<p);x++){
            int c=i-1-__builtin_popcount(x);
            if(c<k) dp[i][x]=dp[i-1][x]+a[i];
            else dp[i][x]=dp[i-1][x];
            for(int j=1;j<=p;j++) if(getbit(j,x)){
                int y=x&(~(1<<(j-1)));
                dp[i][x]=max(dp[i][x],dp[i-1][y]+s[i][j]);
            }
        }
    }
    cout<<dp[n][(1<<p)-1];
}
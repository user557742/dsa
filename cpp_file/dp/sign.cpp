#include <bits/stdc++.h>
using namespace std;
const int maxn =1e2+1;
int a[maxn];int n,k;
int dp[maxn][20001];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    int lim=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lim+=a[i];
    }
    lim=lim+10000;
    dp[1][a[1]+10000]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=lim;j++){
            if(dp[i-1][j]){
                if(j+a[i]<=lim) dp[i][j+a[i]]=1;
                if(j-a[i]>=0) dp[i][j-a[i]]=1;
            }
        }
    }
    cout<<dp[n][k+10000];
    vector<int> ds;
    int gt=k+10000;
    for(int i=n;i>=2;i--){
        if(dp[i-1][gt+a[i]]){
            gt=gt+a[i];
            ds.push_back(0);
            continue;
        }
        if(dp[i-1][gt-a[i]]){
            gt=gt-a[i];
            ds.push_back(1);
        }
    }
    reverse(ds.begin(),ds.end());
    for(int x:ds){
        if(x==1) cout<< "+";
        else  cout<<"-";
    }
}
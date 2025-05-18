
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++) 
#define pb push_back
const int maxn = 1e5+1;
int n,k;
long long cnt[maxn];
vector<int> adj[maxn];
long long dp[50001][501];
long long ds=0;
void dfs(int u,int dad){
    dp[u][0]=1;
    rei(i,1,k) dp[u][i]=0;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        rei(i,1,k) dp[u][i]+=dp[v][i-1];
    }
    ds+=dp[u][k];
    vector<long long >s(k+1,0);
    rei(x,0,k-1) s[x]=0;
    for(int v:adj[u]) if(v!=dad){
        cnt[0]=0;
        rei(d,1,k) cnt[d]=dp[v][d-1];
        rei(d,1,k-1){
            ds+=s[k-d]*cnt[d];
        }
        rei(d,1,k) s[d]+=cnt[d];
    }
}
int main(){
    cin>>n>>k;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    cout<<ds;
}
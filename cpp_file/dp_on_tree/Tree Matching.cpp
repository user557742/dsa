#include <iostream>
#include <vector>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn=2e5+1;
int dp[maxn][2];
vector<int> adj[maxn];int n;
void  dfs(int u,int dad){
    int ans=0;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        dp[u][0]+=max(dp[v][1],dp[v][0]);
        ans+=max(dp[v][1],dp[v][0]);
    }
    for(int v:adj[u]) if(v!=dad){
        dp[u][1]=max(dp[u][1],ans-max(dp[v][1],dp[v][0])+dp[v][0]+1);
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout<<max(dp[1][1],dp[1][0]);
}
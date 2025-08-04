#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
const int mod = 1e9+7;
int n,m;
vector<int> adj[maxn];
long long dp[maxn];
vector<int> topo;
bool vis[maxn];
void dfs(int u,int dad){
    vis[u]=1;
    for(int v:adj[u]) if(v!=dad){
        if(!vis[v]) dfs(v,u);
    }
    topo.push_back(u);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
    reverse(topo.begin(),topo.end());
    dp[1]=1;
    for(int u:topo){
        for(int v:adj[u]) dp[v]=(dp[v]+dp[u])%mod;
    }
    cout<<dp[n];
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int maxn = 2e5+1;
vector<int> adj[maxn];
vector<pair<vector<int>,vector<int>>> tplt;
int vis[maxn];
pair<vector<int>,vector<int>> mu;
int n,m;
void dfs(int u,int ctr){
    if(ctr) mu.se.push_back(u);
    else mu.fi.push_back(u);
    vis[u]=1;
    for(int v:adj[u]) if(!vis[v]) dfs(v,1-ctr);
}
int a[maxn],b[maxn];
int dp[maxn][2];
int gan0(int u,int v){
    if(abs(u)<abs(v)) return u;
    return v;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++) if(!vis[i]){
        mu.fi.clear();mu.se.clear();
        dfs(i,0);
        tplt.push_back(mu);
    }
    /*for(pair<vector<int>,vector<int>> x:tplt){
        for(int u:x.fi) cout<<u<<" ";
        cout<<" | ";
        for(int u:x.se) cout<<u<<" ";
        cout<<"\n";
    }*/
    int lim=tplt.size();
    for(int i=0;i<lim;i++){
        a[i+1]=tplt[i].fi.size();
        b[i+1]=tplt[i].se.size();
    }
    /*int sa=0,sb=0;
    for(int i=1;i<=n;i++){
        sa+=a[i];
        sb+=b[i];
    }
    dp[0][0]=sa-sb;
    dp[0][1]=sb-sa;*/
    for(int i=1;i<=lim;i++){
        dp[i][0]=gan0(dp[i-1][0],dp[i-1][1])+a[i]-b[i];
        dp[i][1]=gan0(dp[i-1][0],dp[i-1][1])+b[i]-a[i];
    }
    int ds=gan0(dp[lim][1],dp[lim][0]);
    int gt=0;
    vector<int> l,r;
    if(ds==dp[lim][1]) gt=1;
    else gt=0;
    if(gt==1)
}

#include <iostream>
#include <vector> 
using namespace std;
const int maxn = 1e5+1;
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
int n;
vector<int > adj[maxn];
int dp[maxn][4];
int a[maxn];
int k;
const int mod=1e9+7;
void dfs(int u,int dad){
    rei(i,1,3) dp[u][i]=1;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        ll ans=0;
        if(a[u]!=0){
            if(a[v]!=0){
                ans+=dp[v][a[v]];
            }
            else{
                rei(i,1,3) if(i!=a[u]) ans+=dp[v][i];
            }
            dp[u][a[u]]=(dp[u][a[u]]*ans)%mod;
        }
        else{
            if(a[v]!=0){
                rei(i,1,3) if(i!=a[v]) 
            }
        }
    }
}
int main(){
    cin>>n>>k;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    while(k--){
        int u,c;cin>>u>>c;
        a[u]=c;
    }
}
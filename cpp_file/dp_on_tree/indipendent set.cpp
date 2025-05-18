#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n;
vector<int> adj[maxn];
ll dp[maxn][2];
void dfs(int u,int dad){
    //if(adj[u].size()<2&&u!=1){
    dp[u][1]=1;
    dp[u][0]=1;
    
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        dp[u][0]=(dp[u][0]*(dp[v][1]+dp[v][0]))%mod;
        dp[u][1]=(dp[u][1]*dp[v][0])%mod;
    }
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    cout<<(dp[1][1]+dp[1][0])%mod;

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
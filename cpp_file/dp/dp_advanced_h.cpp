#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+1;
const int mod=1e3+7;
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
int n;vector<int> adj[maxn];
int dp[maxn][maxn];
int tmp[maxn],sz[maxn];
void dfs(int u,int dad){
    sz[u]=1;
    dp[u][0]=0;
    int ms=0;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        red(i,sz[u],0){
            red(j,sz[v],0) if(i+j<=n){
                dp[u][i+j]=max(dp[u][i]+dp[v][j]+i*j,dp[u][i+j]);
            }
        }
        sz[u]+=sz[v];
        int ans=0;
        rei(i,0,sz[v]) ans=max(ans,dp[v][i]+i);
        ms+=ans;
    }
    dp[u][1]=max(dp[u][1],ms);
}
void solve(){
    cin>>n;
    memset(dp,0,sizeof(0));
    rei(i,1,n) adj[i].clear();
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rei(i,1,n) rei(j,0,n) dp[i][j]=-1e9;
    dfs(1,0);
    int ds=0;
    rei(i,1,n) ds=max(ds,dp[1][i]);
    cout<<ds<<"\n";
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--) solve();

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
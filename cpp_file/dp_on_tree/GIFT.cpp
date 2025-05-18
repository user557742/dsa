// dp[u][x] : chi phi nho nhat de cay con goc u co gia tri la x
/*
th1 : u khong co con 
    +) dp[u][0] = |a[u]|
    +) dp[u][1] = |a[u]-1|
th2 : u co 1 con dp[u][x] = min(dp[v][s]) + |a[u]-x|
th3 : u co 2 con dp[u][t+s] = min(dp[u][t+s],dp[v1][s]+dp[v2][t] + |a[u]-x|)

*/
#include<iostream>
#include<vector>
using namespace std;
const long long inf=1e18;
const int maxn = 5001;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
int n;
int a[maxn];
vector<int> adj[maxn];
typedef long long ll;
ll dp[maxn][maxn];
int sl[maxn];
void dfs(int u,int dad){
    vector<int> con;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        sl[u]+=sl[v];
        con.pb(v);
    }
    rei(i,0,sl[u]) dp[u][i]=inf;
    if(con.empty()){
        sl[u]=1;
        dp[u][0]=abs(a[u]);
        dp[u][1]=abs(a[u]-1);
    }
    else if(con.size()==1){
        int v=con[0];
        rei(x,0,sl[u]) {
            dp[u][x]=dp[v][x]+abs(a[u]-x);
        }
        return;
    }
    else {
        int v1=con[0],v2=con[1];
        rei(x,0,sl[v1]){
            rei(y,0,sl[v2]){
                dp[u][x+y]=min(dp[u][x+y],dp[v1][x]+dp[v2][y]+abs(a[u]-x-y));
            }
        }
    }
}
int main(){
    cin>>n;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    ll ans=1e18;
    rei(i,1,sl[1]) ans=min(dp[1][i],ans);
    cout<<ans; 
    return 0;
}
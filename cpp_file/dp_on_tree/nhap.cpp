#include <iostream>
#include <vector>
#define rei(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int inf = 1e9;
const int maxn = 205;
int n, P;
int c[maxn], dp[maxn][maxn], odp[maxn];
vector<int> adj[maxn];
vector<pair<int,int>> cc[maxn][maxn];
vector<int> ans;
void dfs(int u, int dad){
    rei(k,1,P){
        dp[u][k]=-inf;
        cc[u][k].clear();
    }
    dp[u][1]=c[u];
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        rei(k,1,P) odp[k]=dp[u][k];
        vector<vector<pair<int,int>>> oc(P+1);
        rei(k,1,P) oc[k]=cc[u][k];
        rei(k,1,P){
            dp[u][k]=-inf;
            cc[u][k].clear();
        }
        rei(s,1,P) if(odp[s]>-inf){
            if(odp[s]>dp[u][s]){
                dp[u][s]=odp[s];
                cc[u][s]=oc[s];
            }
            rei(t,1,P-s) if(dp[v][t]>-inf){
                int val=odp[s] + dp[v][t];
                if(val>dp[u][s+t]){
                    dp[u][s+t]=val;
                    cc[u][s+t]=oc[s];
                    cc[u][s+t].push_back(make_pair(v,t));
                }
            }
        }
    }
}

void tim(int u, int need){
    ans.push_back(u);
    for(pair<int,int> pr: cc[u][need]){
        tim(pr.first, pr.second);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>P;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    int ds=-inf, r=1;
    for(int u=1;u<=n;u++){
        if(dp[u][P]>ds){
            ds = dp[u][P];
            r = u;
        }
    }
    ans.clear();
    tim(r,P);
    for(int x:ans) cout<<x<<' ';
    return 0;
}

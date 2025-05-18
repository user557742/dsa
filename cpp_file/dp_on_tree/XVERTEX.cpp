#include <iostream>
#include <vector>
#include<algorithm>
typedef long long ll;
#define rei(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int inf = 1e9;
const int maxn = 205;
int n, P;
int c[maxn], dp[maxn][maxn], odp[maxn];
vector<int> adj[maxn];
vector<int> ans;
bool vis[maxn];
void dfs(int u, int dad){
    vis[u]=1;
    rei(k,1,P){
        dp[u][k]=inf;
    }
    dp[u][1]=c[u];
    for(int v:adj[u]) if(v!=dad&&!vis[v]){
        dfs(v,u);
        rei(k,1,P) odp[k]=dp[u][k];
        rei(k,1,P){
            dp[u][k]=inf;
        }
        rei(s,1,P) {
            if(odp[s]<dp[u][s]){
                dp[u][s]=odp[s];
            }
            rei(t,1,P-s) {
                int val=odp[s] + dp[v][t];
                if(val<dp[u][s+t]){
                    dp[u][s+t]=val;
                }
            }
        }
    }
}
pair<ll,int> gt[maxn];
int s[maxn];
ll tmp[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin>>n>>m;
    P=n;
    for(int i=1;i<=n;i++) cin>>c[i];
    while(m--){int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> goc;
    rei(i,1,n){
        if(!vis[i]){
            goc.push_back(i);
            dfs(i,0);
        }
    }
    int id=0;
    for(int r:goc){
        rei(x,1,n){
            id+=1;
            gt[id]={dp[r][x],x};
        }
    }
    sort(gt+1,gt+id+1);
    s[0]=-1e9;
    rei(i,1,id){
        tmp[i]=gt[i].first;
        s[i]=max(s[i-1],gt[i].second);
    }
    
    int q;cin>>q;
    while(q--){
        int u;cin>>u;
        int i=upper_bound(tmp+1,tmp+id+1,u)-tmp-1;
        if(s[i]<2) cout<<"0\n";
        else cout<<s[i]<<"\n";
    }
    
}

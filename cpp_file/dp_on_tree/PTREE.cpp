#include<iostream>
#include <vector>
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
const int oo=1e9;
const int maxn=201;
int n,p;
int c[maxn];
int dp[maxn][maxn];
vector<int> adj[maxn];

int ccnt[maxn][maxn][maxn];

int cnt[maxn],ch[maxn][maxn];
vector<int> ans;
void dfs(int u,int dad){
    rei(k,1,p){
        dp[u][k]=-oo;
        rei(j,1,n) ccnt[u][j][k]=0;
    }
    dp[u][1]=c[u];
    cnt[u]=0;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
        int j=++cnt[u];
        ch[u][j]=v;
        vector<int> odp(p+1,-oo);
        rei(s,1,p) odp[s]=dp[u][s];
        
        vector<vector<int>> ocnt(j,vector<int>(p+1,0));
        rei(ii,1,j-1) rei(s,1,p) ocnt[ii][s]=ccnt[u][ii][s];

        rei(s,1,p){
            dp[u][s]=-oo;
            rei(ii,1,j) ccnt[u][ii][s]=0;
        }
        rei(s,1,p){
            if(odp[s]<=-oo) continue;
            if(odp[s]>dp[u][s]){
                dp[u][s]=odp[s];
                rei(ii,1,j-1) ccnt[u][ii][s]=ocnt[ii][s];
                ccnt[u][j][s]=0;
            }
            rei(t,1,p-s){
                if(dp[v][t]<=-oo) continue;
                int val=odp[s]+dp[v][t];
                if(val>dp[u][s+t]){
                    dp[u][s+t]=val;
                    rei(ii,1,j-1) ccnt[u][ii][s+t]=ocnt[ii][s];
                    ccnt[u][j][s+t]=t;
                }
            }
        }
        
    }
}
void tim(int u,int cc){
    ans.pb(u);
    rei(j,1,cnt[u]){
        int t=ccnt[u][j][cc];
        if(t>0){
            int v=ch[u][j];
            tim(v,t);
            cc-=t;
        }
    }
}
int main(){
    cin>>n>>p;
    rei(i,1,n) cin>>c[i];
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    int r=1;
    int ds=-oo;
    rei(u,1,n) {
        if(dp[u][p]>ds){
            ds=dp[u][p];
            r=u;
        }
    }
    tim(r,p);
    for(int x:ans) cout<<x<<" ";
}
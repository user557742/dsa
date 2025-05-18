#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5+1;
#define rei(i,a,b) for(int i = (a); i <= (b); i++)
int n;
vector<int> adj[maxn];
int dp[maxn],upv[maxn],mx1[maxn],mx2[maxn],who[maxn];
void dfs1(int u, int p) {
    mx1[u] = mx2[u] = 0;
    who[u] = 0;
    for (int v : adj[u]) if (v != p) {
        dfs1(v, u);
        int d = dp[v] + 1;
        if (d > mx1[u]) {
            mx2[u] = mx1[u];
            mx1[u] = d;
            who[u] = v;
        }
        else if (d > mx2[u]) {
            mx2[u] = d;
        }
    }
    dp[u] = mx1[u];
}
void dfs2(int u, int p) {
    for (int v : adj[u]) if (v != p) {
        int use = (who[u] == v ? mx2[u] : mx1[u]);
        upv[v] = max(upv[u], use) + 1;
        dfs2(v, u);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    rei(i,1,n-1){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    upv[1] = 0;
    dfs2(1, 0);
    rei(u,1,n){
        cout << max(dp[u], upv[u]) << " ";
    }
    return 0;
}

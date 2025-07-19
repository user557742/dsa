#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2005;
const ll INF = (ll)1e18;

int n;
vector<int> adj[MAXN];
ll a[MAXN], b[MAXN];
ll dp[MAXN][MAXN], sa[MAXN][MAXN], sb[MAXN][MAXN];
int sz[MAXN];

void dfs(int u){
    // 1) Kh?i t?o cho u: khi chua xét con nào
    sz[u] = 1;
    dp[u][0] = 0;
    sa[u][0] = 0;
    sb[u][0] = 0;

    // 2) Merge l?n lu?t t?ng con v
    for(int v: adj[u]){
        // sao chép giá tr? cu tru?c khi merge
        static ll old_dp[MAXN], old_sa[MAXN], old_sb[MAXN];
        for(int i = 0; i < sz[u]; ++i){
            old_dp[i] = dp[u][i];
            old_sa[i] = sa[u][i];
            old_sb[i] = sb[u][i];
        }
        // reset vùng c?n merge
        for(int i = 0; i <= sz[u] + sz[v]; ++i){
            dp[u][i] = sa[u][i] = sb[u][i] = INF;
        }
        // dfs con v
        dfs(v);
        // merge subtree v vào u
        for(int i = 0; i < sz[u]; ++i){
            for(int j = 0; j < sz[v]; ++j){
                // u không di làm
                dp[u][i+j] = min(dp[u][i+j], old_dp[i] + dp[v][j]);
                sa[u][i+j] = min(sa[u][i+j], old_sa[i] + sa[v][j]);
                sb[u][i+j] = min(sb[u][i+j], old_sb[i] + sb[v][j]);
            }
        }
        // c?p nh?t kích thu?c sau merge
        sz[u] += sz[v];
    }

    // 3) Xét tru?ng h?p u di làm (t? x -> x+1)
    for(int i = sz[u]-1; i >= 0; --i){
        // dùng sa ho?c sb
        ll bestExtra = min(sa[u][i], sb[u][i]);
        dp[u][i+1] = min(dp[u][i+1], dp[u][i] + bestExtra);
        // c?p nh?t sa/sb cho vi?c u du?c ch?n
        sa[u][i+1] = min(sa[u][i+1], sa[u][i] + a[u]);
        sb[u][i+1] = min(sb[u][i+1], sb[u][i] + b[u]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--){
        cin >> n;
        // reset
        for(int i = 1; i <= n; ++i){
            adj[i].clear();
            for(int j = 0; j <= n; ++j){
                dp[i][j] = sa[i][j] = sb[i][j] = INF;
            }
        }
        // build tree
        for(int i = 2; i <= n; ++i){
            int p; cin >> p;
            adj[p].push_back(i);
        }
        // read a[], b[]
        for(int i = 2; i <= n; ++i) cin >> a[i];
        for(int i = 2; i <= n; ++i) cin >> b[i];

        dfs(1);

        // output dp[1][1..n]
        for(int m = 1; m <= n; ++m){
            cout << dp[1][m] << (m==n?'\n':' ');
        }
    }
    return 0;
}


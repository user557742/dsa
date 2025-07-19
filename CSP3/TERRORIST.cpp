#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 5;
using ll = long long;

int n, m, q;
vector<int> adj[maxn];
pair<int,int> e[maxn];
bool br[maxn];
int tin[maxn], low[maxn], tmr;
int dep[maxn], st[maxn], eid;
pair<int,int> rmq[19][2*maxn];

void dfs1(int u, int p){
    st[u] = eid;
    rmq[0][eid++] = {dep[u], u};
    for(int v: adj[u]) if(v != p){
        dep[v] = dep[u] + 1;
        dfs1(v, u);
        rmq[0][eid++] = {dep[u], u};
    }
}

void prep(){
    int N = eid, K = __lg(N);
    for(int i = 1; i <= K; i++)
        for(int j = 0; j + (1<<i) <= N; j++)
            rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j + (1<<(i-1))]);
}

int lca(int u, int v){
    int L = st[u], R = st[v];
    if(L > R) swap(L, R);
    int k = __lg(R - L + 1);
    return min(rmq[k][L], rmq[k][R - (1<<k) + 1]).second;
}
void dfs2(int u, int pe){
    tin[u] = low[u] = ++tmr;
    for(int i: adj[u]){
        int v = e[i].first == u ? e[i].second : e[i].first;
        if(i == pe) continue;
        if(!tin[v]){
            dfs2(v, i);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) br[i] = 1;
        } else low[u] = min(low[u], tin[v]);
    }
}

int c[maxn], inE[maxn], pc;
vector<int> tr[maxn];

int main(){
    if(fopen("TERRORIST.INP","r")){
        freopen("TERRORIST.INP","r",stdin);
        freopen("TERRORIST.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        e[i] = {u, v};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }
    if(m == n-1){
        dep[1] = 0; eid = 0;
        dfs1(1, 0);
        prep();
        cin >> q;
        while(q--){
            int u, v; cin >> u >> v;
            int w = lca(u, v);
            int d = dep[u] + dep[v] - 2*dep[w];
            cout << d << " " << d << "\n";
        }
        return 0;
    }
    cin >> q;
    memset(tin, 0, sizeof(int)*(n+1));
    memset(br, 0, sizeof(bool)*m);
    tmr = 0;
    for(int i = 1; i <= n; i++)
        if(!tin[i]) dfs2(i, -1);
    memset(c, -1, sizeof(int)*(n+1));
    pc = 0;
    function<void(int)> dfs3 = [&](int u){
        for(int i: adj[u]){
            if(br[i]) continue;
            int v = e[i].first == u ? e[i].second : e[i].first;
            if(c[v] == -1){
                c[v] = c[u];
                dfs3(v);
            }
        }
    };
    for(int i = 1; i <= n; i++){
        if(c[i] == -1){
            c[i] = pc;
            dfs3(i);
            pc++;
        }
    }
    fill(inE, inE+pc, 0);
    for(int i = 0; i < m; i++)
        if(!br[i]) inE[c[e[i].first]]++;
    for(int i = 0; i < pc; i++) tr[i].clear();
    for(int i = 0; i < m; i++){
        if(br[i]){
            int u = c[e[i].first], v = c[e[i].second];
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
    }

    while(q--){
        int x, y; cin >> x >> y;
        int cx = c[x], cy = c[y];
        if(cx == cy){
            cout << 0 << " " << inE[cx] << "\n";
            continue;
        }
        vector<int> p(pc, -1), path;
        queue<int> qu;
        qu.push(cx);
        p[cx] = cx;
        while(!qu.empty() && p[cy] == -1){
            int u = qu.front(); qu.pop();
            for(int v: tr[u]){
                if(p[v] == -1){
                    p[v] = u;
                    qu.push(v);
                }
            }
        }
        int cur = cy;
        while(cur != p[cur]){
            path.push_back(cur);
            cur = p[cur];
        }
        path.push_back(cx);

        int k = path.size(), nb = k - 1;
        ll sum = 0;
        for(int v: path) sum += inE[v];
        cout << nb << " " << (sum + nb) << "\n";
    }
    return 0;
}


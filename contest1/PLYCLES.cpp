#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int maxn = 2e5+1;
int n, M;
vector<int> g[maxn];
int h[maxn], to[6*maxn], nx[6*maxn], ec;
int* f[maxn], fsz[maxn], sz[maxn];
vector<array<int, 3>> tri;
inline int sd(int u, int v) {
    int d = v - u;
    if (d < 0) d += n;
    return d;
}
inline void am(int &x, ll v) {
    x = (x + v) % mod;
}
void ae(int u, int v) {
    to[ec] = v;
    nx[ec] = h[u];
    h[u] = ec++;
}
void ds(int u, int p) {
    sz[u] = 1;
    for (int e = h[u]; e != -1; e = nx[e]) {
        int v = to[e];
        if (v == p) continue;
        ds(v, u);
        sz[u] += sz[v];
    }
    fsz[u] = sz[u] + 1;
    f[u] = new int[fsz[u]]();
}
void dd(int u, int p) {
    f[u][1] = 1;
    int cur = 2;
    for (int e = h[u]; e != -1; e = nx[e]) {
        int v = to[e];
        if (v == p) continue;
        dd(v, u);
        int nxt_sz = cur + fsz[v] - 1;
        int *tmp = new int[nxt_sz]();
        for (int i = 1; i < cur; ++i) {
            if (!f[u][i]) continue;
            for (int j = 0; j < fsz[v]; ++j) {
                int ways = (j == 0 ? 1 : f[v][j]);
                am(tmp[i + j], (ll)f[u][i] * ways);
            }
        }
        delete[] f[u];
        f[u] = tmp;
        cur = nxt_sz;
    }

    fsz[u] = cur;
}
int main() {
    if(fopen("PCYCLES.INP","r")){
        freopen("PCYCLES.INP","r",stdin);
        freopen("PCYCLES.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    g[n].push_back(1);
    g[1].push_back(n);
    for (int i = 0, u, v; i < n - 3; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int u = 1; u <= n; ++u) {
        sort(g[u].begin(), g[u].end(), [&](int a, int b) {
            return sd(u, a) < sd(u, b);
        });
    }
    for (int u = 1; u <= n; ++u) {
        auto &v = g[u];
        for (int i = 0; i + 1 < (int)v.size(); ++i) {
            array<int, 3> t = {u, v[i], v[i + 1]};
            sort(t.begin(), t.end());
            tri.push_back(t);
        }
    }
    sort(tri.begin(), tri.end());
    tri.erase(unique(tri.begin(), tri.end()), tri.end());
    M = tri.size(); 
    memset(h, -1, sizeof h);
    ec = 0;
    unordered_map<ll,int> mp;
    mp.reserve(M * 3);
    for (int i = 0; i < M; ++i) {
        for (int k = 0; k < 3; ++k) {
            int a = tri[i][k];
            int b = tri[i][(k + 1) % 3];
            int u = min(a, b);
            int v2 = max(a, b);
            ll key = ((ll)u << 32) | v2;

            auto it = mp.find(key);
            if (it == mp.end()) {
                mp[key] = i;
            } else {
                ae(i, it->second);
                ae(it->second, i);
            }
        }
    }
    ds(0, -1);
    dd(0, -1);
    ll ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 1; j < fsz[i]; ++j) {
            ans = (ans + f[i][j]) % mod;
        }
    }
    cout << ans;
    return 0;
}

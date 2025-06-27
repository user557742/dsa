#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
int n, q;
vector<pair<int,int>> adj[maxn];

struct E { int u, v, l; } e[maxn];

int sz[maxn], pre[maxn], depth[maxn];
int heavy[maxn], head[maxn], pos[maxn];
int edgeToParent[maxn], invVal[maxn];
int id = 0;

struct it {
    int gmin[4*maxn], gmax[4*maxn], lz[4*maxn];
    inline void init() {
        for (int i = 1; i <= 4*n; i++) lz[i] = 1;
    }
    inline void apply(int r) {
        int omi = gmin[r], oma = gmax[r];
        gmin[r] = -oma;
        gmax[r] = -omi;
        lz[r] = -lz[r];
    }
    inline void push(int r) {
        if (lz[r] == -1) {
            apply(2*r);
            apply(2*r+1);
            lz[r] = 1;
        }
    }
    inline void pull(int r) {
        gmin[r] = min(gmin[2*r], gmin[2*r+1]);
        gmax[r] = max(gmax[2*r], gmax[2*r+1]);
    }
    void build(int r, int lo, int hi) {
        lz[r] = 1;
        if (lo == hi) {
            gmin[r] = gmax[r] = invVal[lo];
            return;
        }
        int mid = (lo + hi) >> 1;
        build(2*r, lo, mid);
        build(2*r+1, mid+1, hi);
        pull(r);
    }
    void change(int k, int x, int r = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            gmin[r] = gmax[r] = x;
            lz[r] = 1;
            return;
        }
        push(r);
        int mid = (lo + hi) >> 1;
        if (k <= mid) change(k, x, 2*r, lo, mid);
        else change(k, x, 2*r+1, mid+1, hi);
        pull(r);
    }
    void neg(int u, int v, int r = 1, int lo = 1, int hi = n) {
        if (v < lo || hi < u) return;
        if (u <= lo && hi <= v) {
            apply(r);
            return;
        }
        push(r);
        int mid = (lo + hi) >> 1;
        neg(u, v, 2*r, lo, mid);
        neg(u, v, 2*r+1, mid+1, hi);
        pull(r);
    }
    int getMax(int u, int v, int r = 1, int lo = 1, int hi = n) {
        if (v < lo || hi < u) return INT_MIN;
        if (u <= lo && hi <= v) return gmax[r];
        push(r);
        int mid = (lo + hi) >> 1;
        return max(getMax(u,v,2*r,lo,mid), getMax(u,v,2*r+1,mid+1,hi));
    }
} t;

int dfs(int u, int p, int pe) {
    pre[u] = p;
    edgeToParent[u] = pe;
    sz[u] = 1;
    heavy[u] = -1;
    int maxsz = 0;
    for (auto &pr : adj[u]) {
        int v = pr.first, idx = pr.second;
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int s = dfs(v, u, idx);
        if (s > maxsz) { maxsz = s; heavy[u] = v; }
        sz[u] += s;
    }
    return sz[u];
}

void hld(int u, int h) {
    head[u] = h;
    pos[u] = ++id;
    invVal[id] = (edgeToParent[u] == 0 ? INT_MIN : e[edgeToParent[u]].l);
    if (heavy[u] != -1) hld(heavy[u], h);
    for (auto &pr : adj[u]) {
        int v = pr.first;
        if (v != pre[u] && v != heavy[u])
            hld(v, v);
    }
}

void truyvan1() {
    int i, v; cin >> i >> v;
    int u = e[i].u, w = e[i].v;
    if (depth[u] > depth[w]) swap(u,w);
    t.change(pos[w], v);
}

void truyvan2() {
    int u, v; cin >> u >> v;
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) {
            t.neg(pos[head[u]], pos[u]);
            u = pre[head[u]];
        } else {
            t.neg(pos[head[v]], pos[v]);
            v = pre[head[v]];
        }
    }
    if (depth[u] > depth[v]) swap(u,v);
    t.neg(pos[u]+1, pos[v]);
}

void truyvan3() {
    int u, v; cin >> u >> v;
    int ans = INT_MIN;
    while (head[u] != head[v]) {
        if (depth[head[u]] > depth[head[v]]) {
            ans = max(ans, t.getMax(pos[head[u]], pos[u]));
            u = pre[head[u]];
        } else {
            ans = max(ans, t.getMax(pos[head[v]], pos[v]));
            v = pre[head[v]];
        }
    }
    if (depth[u] > depth[v]) swap(u,v);
    ans = max(ans, t.getMax(pos[u]+1, pos[v]));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        cin >> e[i].u >> e[i].v >> e[i].l;
        adj[e[i].u].emplace_back(e[i].v, i);
        adj[e[i].v].emplace_back(e[i].u, i);
    }
    depth[1] = 0;
    dfs(1, 0, 0);
    hld(1, 1);

    t.init();
    t.build(1, 1, n);

    while (q--) {
        string op; cin >> op;
        if (op == "CHANGE") truyvan1();
        else if (op == "NEGATE") truyvan2();
        else if (op == "QUERY") truyvan3();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 100005;
const int MAXM = 200005;
const ll INF = 4e18;

struct Edge {
    int to, id;
    ll w;
};

int n, m, s, t, q;
int U[MAXM], V[MAXM];
ll W[MAXM];
vector<Edge> g[MAXN];

// Sub trâu
ll run_dij_trau(int banV, int banE) {
    vector<ll> d(n + 1, INF);
    vector<bool> vis(n + 1, false);

    if (s == banV) return INF;
    d[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        int u = p.second;
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = 0; i < (int)g[u].size(); ++i) {
            Edge e = g[u][i];
            if (e.id == banE) continue;
            if (e.to == banV) continue;
            int v = e.to;
            ll nd = d[u] + e.w;
            if (nd < d[v]) {
                d[v] = nd;
                pq.push({nd, v});
            }
        }
    }

    return d[t];
}

// Sub full
ll d1[MAXN], d2[MAXN];
ll cnt1[MAXN], cnt2[MAXN];

void dijkstra(int st, ll d[], ll cnt[]) {
    fill(d, d + n + 1, INF);
    fill(cnt, cnt + n + 1, 0);
    d[st] = 0;
    cnt[st] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        pair<ll, int> p = pq.top(); pq.pop();
        int u = p.second;
        if (p.first > d[u]) continue;
        for (int i = 0; i < (int)g[u].size(); ++i) {
            Edge e = g[u][i];
            int v = e.to;
            ll nd = d[u] + e.w;
            if (nd < d[v]) {
                d[v] = nd;
                cnt[v] = cnt[u];
                pq.push({nd, v});
            } else if (nd == d[v]) {
                cnt[v] += cnt[u];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; ++i) {
        cin >> U[i] >> V[i] >> W[i];
        g[U[i]].push_back({V[i], i, W[i]});
    }

    cin >> q;
    if (n <= 2000) {
        while (q--) {
            char typ;
            int x;
            cin >> typ >> x;
            ll res;
            if (typ == 'V') {
                res = run_dij_trau(x, 0);
            } else {
                res = run_dij_trau(0, x);
            }
            if (res >= INF) cout << -1 << '\n';
            else cout << res << '\n';
        }
    } else {
        dijkstra(s, d1, cnt1);
        dijkstra(t, d2, cnt2);
        ll shortest = d1[t];
        ll totalPaths = cnt1[t];

        while (q--) {
            char typ;
            int x;
            cin >> typ >> x;
            if (typ == 'V') {
                if (x == s || x == t || d1[x] + d2[x] != shortest || cnt1[x] * cnt2[x] != totalPaths)
                    cout << shortest << '\n';
                else cout << -1 << '\n';
            } else {
                int u = U[x], v = V[x];
                ll w = W[x];
                if (d1[u] + w + d2[v] == shortest && cnt1[u] * cnt2[v] == totalPaths)
                    cout << -1 << '\n';
                else cout << shortest << '\n';
            }
        }
    }

    return 0;
}

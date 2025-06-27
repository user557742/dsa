#include <bits/stdc++.h>
#include "PATHQR2.h"
using namespace std;
const int maxn = 2e5 + 1;
int n;int a[maxn];
vector<int> adj[maxn];
int sz[maxn], pre[maxn];
int heavy[maxn], head[maxn];
int pos[maxn], id = 0,depth[maxn];
typedef long long ll;
struct IT {
	ll s[4 * maxn];
	void upd(int u, int x, int r = 1, int lo = 1, int hi = n) {
		if (u<lo || u>hi) return;
		if (lo == hi) {
			s[r] = x;
			return;
		}
		int mid = (lo + hi) / 2;
		upd(u, x, 2 * r, lo, mid);
		upd(u, x, 2 * r + 1, mid + 1, hi);
		s[r] = max(s[2 * r], s[2 * r + 1]);
	}
	ll getans(int u, int v, int r = 1, int lo = 1, int hi = n) {
		if (u > hi || v < lo) return LLONG_MIN;
		if (u <= lo && hi <= v) return s[r];
		int mid = (lo + hi) / 2;
		ll sl = getans(u, v, 2 * r, lo, mid);
		ll sr = getans(u, v, 2 * r + 1, mid + 1, hi);
		return max(sl, sr);
	}
} t;
void dfs(int u, int dad) {
	sz[u] = 1;
	pre[u] = dad;
	heavy[u] = -1;
	int cm = -1;
	for (int v : adj[u]) if (v != dad) {
		dfs(v, u);
		sz[u] += sz[v];
		if (cm < sz[v]) {
			cm = sz[v];
			heavy[u] = v;
		}
	}
}
void HLD(int u, int h) {
	head[u] = h;
	if (u != h) depth[u] = depth[h];
	else  depth[u] = depth[pre[u]] + 1;
	pos[u] = ++id;
	if (heavy[u] != 0) {
		HLD(heavy[u], h);
	}
	for (int v : adj[u]) if (v != pre[u] && v != heavy[u]) HLD(v, v);
}
ll que(int u, int v) {
	ll ds = LLONG_MIN;
	while (head[u] != head[v]) {
		if (depth[head[u]] > depth[head[v]]) {
			cout << t.getans(pos[head[u]], pos[u]) << " ";
			ds = max(ds, t.getans(pos[head[u]], pos[u]));
			u = pre[head[u]];
		}
		else {
			ds = max(ds, t.getans(pos[head[v]], pos[v]));
			v = pre[head[v]];
		}
	}
	if (pos[u] > pos[v]) swap(u, v);
	ds = max(ds, t.getans(pos[u], pos[v]));
	return ds;
}
void main2() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	dfs(1, 1);
	HLD(1, 1);
	for (int i = 1; i <= n; i++) t.upd(pos[i], a[i]);
	while (q--) {
		int loai; cin >> loai;
		if (loai == 1) {
			int k, x; cin >> k >> x;
			t.upd(pos[k], x);
		}
		else {
			int u, v; cin >> u >> v;
			cout << que(u, v) << "\n";
		}
	}
}
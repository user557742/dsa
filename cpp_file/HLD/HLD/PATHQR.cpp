#include <bits/stdc++.h>
#include "PATHQR.h"
using namespace std;
const int maxn = 2e5 + 1;
#define rei(i,a,b) for(int i=a;i<=b;i++)
int n;
int a[maxn];
vector<int> adj[maxn];
typedef long long ll;
struct it{
	ll s[4 * maxn];
	void upd(int k, int x, int r = 1, int lo = 1, int hi = n) {
		if (lo == hi) {
			s[r] = x;
			return;
		}
		int mid = (lo + hi) / 2;
		if (k <= mid) upd(k, x, 2 * r, lo, mid);
		else upd(k, x, 2 * r + 1, mid + 1, hi);
		s[r] = s[2 * r] + s[2 * r + 1];
	}
	ll getans(int u, int v, int r = 1, int lo = 1, int hi = n) {
		if (u > hi || v < lo) return 0;
		if (u <= lo && hi <= v) return s[r];
		int mid = (lo + hi) / 2;
		return getans(u, v, 2 * r, lo, mid) + getans(u, v, 2 * r + 1, mid + 1, hi);
	}
}t;
int pos[maxn], depth[maxn],id=0;
int head[maxn], heavy[maxn],pre[maxn];
int dfs(int u) {
	heavy[u] = -1;
	int cm = -1;
	int sz = 1;
	for (int v : adj[u]) {
		if (v != pre[u]) {
			pre[v] = u;
			int csz=dfs(v);
			sz += csz;
			if (cm < csz) {
				cm = csz;
				heavy[u] = v;
			}
		}
	}
	return sz;
}
void HLD(int u, int h) {
	head[u] = h;
	pos[u] = ++id;
	if (head[u] != u) depth[u] = depth[h];
	else depth[u] = depth[pre[u]] + 1;
	if (heavy[u] != -1) HLD(heavy[u], h);
	for (int v : adj[u]) if (v != pre[u] && heavy[u] != v) HLD(v, v);
}
ll quer(int u,int v){
	ll ds = 0;
	while (head[u] != head[v]) {
		if(depth[head[u]]>depth[head[v]]) {
			ds += t.getans(pos[head[u]], pos[u]);
			u = pre[head[u]];
		}
		else {
			ds += t.getans(pos[head[v]], pos[v]);
			v = pre[head[v]];
		}
	}
	if (pos[u] > pos[v]) swap(u, v);
	ds += t.getans(pos[u], pos[v]);
	return ds;
}
void main1() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int q;
	cin >> n >> q;
	rei(i, 1, n) cin >> a[i];
	rei(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	HLD(1, 1);
	rei(i, 1, n) t.upd(pos[i], a[i]);
	while (q--) {
		int loai; cin >> loai;
		if (loai == 1) {
			int k,  x;
			cin >> k >> x;
			t.upd(pos[k], x);
		}
		else {
			int u; cin >> u;
			cout << quer(1, u) << "\n";
		}
	}
}
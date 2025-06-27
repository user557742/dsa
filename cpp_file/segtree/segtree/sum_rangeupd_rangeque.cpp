#include <bits/stdc++.h>
#include "sum_rangeupd_rangeque.h"
using namespace std;

#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 1e5 + 1;
int n;
int a[maxn];
typedef long long ll;
struct node {
	ll s=0;
	ll lz=0;
	node(int _s=0,int _lz=0) : s(_s),lz(_lz) {}
}; 
struct it {
	node g[4 * maxn];
	void build(int r = 1, int lo = 1, int hi = n) {
		if (lo == hi) {
			g[r].s = a[lo];
			return;
		}
		int mid = (lo + hi) / 2;
		build(2 * r, lo, mid);
		build(2 * r + 1, mid + 1, hi);
		g[r].s = g[2 * r].s + g[2 * r + 1].s;
	}
	void down(int r,int lo,int hi) {
		int mid = (lo + hi) / 2;
		g[2*r].s += g[r].lz * (mid - lo + 1);
		g[2*r+1].s+=g[r].lz*(hi-mid);
		g[2 * r].lz += g[r].lz;
		g[2 * r + 1].lz += g[r].lz;
		g[r].lz = 0;
	}
	void upd(int u, int v, int x, int r = 1, int lo = 1, int hi = n) {
		if (u > hi || v < lo) return;
		if (u <= lo && hi <= v) {
			g[r].lz += x;
			g[r].s = g[r].s + g[r].lz * (hi - lo + 1);
			return;
		}
		down(r, lo, hi);
		int mid = (lo + hi) / 2;
		upd(u, v, x, 2 * r, lo, mid);
		upd(u, v, x, 2 * r + 1, mid + 1, hi);
		g[r].s = g[2 * r].s + g[2 * r + 1].s ;
	}
	ll getans(int u, int v, int r = 1, int lo = 1, int hi = n) {
		if (u > hi || v < lo) return 0;
		if (u <= lo && hi <= v) return g[r].s + g[r].lz * (hi - lo + 1);
		int mid = (lo + hi) / 2;
		down(r, lo, hi);
		ll L = getans(u, v, 2 * r, lo, mid);
		ll R = getans(u, v, 2 * r + 1, mid + 1, hi);
		return L + R;
	}
}t;
void truyvan1() {
	int u, v, x; cin >> u >> v >> x;
	t.upd(u, v, x);
}
void truyvan2() {
	int u, v; cin >> u >> v;
	cout << t.getans(u, v) << "\n";
}
void main1() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	rei(i, 1, n) cin >> a[i];
	t.build();
	int q; cin >> q;
	while (q--) {
		int l; cin >> l;
		if (l == 1) truyvan1();
		else truyvan2();
	}
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,a[maxn];
int k;
pair<int,int> nv[maxn];
#define fi first
#define se second
vector<int> adj[maxn];
typedef long long ll;
ll dp[maxn];
const ll inf=1e18;
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
		s[r] = max(s[2 * r] , s[2 * r + 1]);
	}
	ll getans(int u, int v, int r = 1, int lo = 1, int hi = n) {
		if (u > hi || v < lo) return 0;
		if (u <= lo && hi <= v) return s[r];
		int mid = (lo + hi) / 2;
		return max(getans(u, v, 2 * r, lo, mid) , getans(u, v, 2 * r + 1, mid + 1, hi));
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
ll cost(int u,int v){
	ll ds = 0;
	while (head[u] != head[v]) {
		if(depth[head[u]]>depth[head[v]]) {
			ds=max(ds, t.getans(pos[head[u]], pos[u]));
			u = pre[head[u]];
		}
		else {
			ds = max(t.getans(pos[head[v]], pos[v]),ds);
			v = pre[head[v]];
		}
	}
	if (pos[u] > pos[v]) swap(u, v);
	ds =max( t.getans(pos[u], pos[v]),ds);
	return ds;
}
ll gt[maxn];
int main(){
    if(fopen("SHIP.inp","r")){
        freopen("SHIP.inp","r",stdin);
        freopen("SHIP.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    HLD(1,1);
    for(int i=1;i<=n;i++) t.upd(pos[i],a[i]);
    cin>>k;
    for(int i=1;i<=k;i++) cin>>nv[i].fi>>nv[i].se;
    for(int i=1;i<=k;i++) dp[i]=-inf;
    for(int i=1;i<=n;i++) gt[i]=-inf;
    nv[0].se=1;
    gt[1]=0;
    for(int i=1;i<=k;i++){
        dp[i]=gt[nv[i].fi]+cost(nv[i].fi,nv[i].se);
        gt[nv[i].se]=max(gt[nv[i].se],dp[i]);
    }
    ll ds=-inf;
    for(int i=1;i<=k;i++) ds=max(ds,dp[i]);
    cout<<ds;
}

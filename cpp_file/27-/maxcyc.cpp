#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
#define rei(i,a,b) for(int i=(a); i<=(b); i++)

struct it {
    int lim = 0;
    int smax[4*maxn];
    int smin[4*maxn];

    void init(int _n){
        lim = _n;
        rei(i,1,4*lim){
            smax[i] = -1000000000;
            smin[i] =  1000000000;
        }
    }
    void upd(int k, int x){
        upd(1, 1, lim, k, x);
    }
    int getmax(int u, int v){
        return getmax(1, 1, lim, u, v);
    }
    int getmin(int u, int v){
        return getmin(1, 1, lim, u, v);
    }
    void upd(int r, int lo, int hi, int k, int x){
        if(lo == hi){
            smax[r] = smin[r] = x;
            return;
        }
        int mid = (lo + hi) >> 1;
        if(k <= mid) upd(r<<1,   lo, mid, k, x);
        else         upd(r<<1|1, mid+1, hi, k, x);
        smax[r] = max(smax[r<<1], smax[r<<1|1]);
        smin[r] = min(smin[r<<1], smin[r<<1|1]);
    }
    int getmax(int r, int lo, int hi, int u, int v){
        if(v < lo || hi < u) return -1000000000;
        if(u <= lo && hi <= v) return smax[r];
        int mid = (lo + hi) >> 1;
        return max(
            getmax(r<<1,   lo, mid, u, v),
            getmax(r<<1|1, mid+1, hi, u, v)
        );
    }
    int getmin(int r, int lo, int hi, int u, int v){
        if(v < lo || hi < u) return 1000000000;
        if(u <= lo && hi <= v) return smin[r];
        int mid = (lo + hi) >> 1;
        return min(
            getmin(r<<1,   lo, mid, u, v),
            getmin(r<<1|1, mid+1, hi, u, v)
        );
    }
} t;

struct DSU {
    int pre[4*maxn], sz[4*maxn];
    void init(int n){
        rei(i,1,n){
            pre[i] = i;
            sz[i] = 1;
        }
    }
    int find(int u){
        return pre[u]==u ? u : pre[u] = find(pre[u]);
    }
    bool unite(int u, int v){
        u = find(u); v = find(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u,v);
        pre[v] = u;
        sz[u] += sz[v];
        return true;
    }
} dsu;

struct E { int u, v, l; } e[maxn];
bool cmpE(const E &a, const E &b){ return a.l > b.l; }

int n, m;
vector<int> adj[maxn];
bool in_mst[maxn];
int parent_[maxn], depth_[maxn], heavy[maxn], head[maxn], pos[maxn], sz_[maxn], curPos;
int wpar[maxn];

int dfs(int u, int p){
    parent_[u] = p;
    sz_[u] = 1;
    heavy[u] = -1;
    int maxSz = 0;
    for(int ei : adj[u]){
        int v = e[ei].u ^ e[ei].v ^ u;
        if(v == p) continue;
        depth_[v] = depth_[u] + 1;
        wpar[v] = e[ei].l;
        int sub = dfs(v, u);
        if(sub > maxSz){
            maxSz = sub;
            heavy[u] = v;
        }
        sz_[u] += sub;
    }
    return sz_[u];
}

void decompose(int u, int h){
    head[u] = h;
    pos[u] = ++curPos;
    if(heavy[u] != -1)
        decompose(heavy[u], h);
    for(int ei : adj[u]){
        int v = e[ei].u ^ e[ei].v ^ u;
        if(v == parent_[u] || v == heavy[u]) continue;
        decompose(v, v);
    }
}

pair<int,int> queryPath(int u, int v){
    if(u == v) return { -1000000000, 1000000000 };
    int mx = -1000000000, mn = 1000000000;
    while(head[u] != head[v]){
        if(depth_[head[u]] > depth_[head[v]]) swap(u,v);
        mx = max(mx, t.getmax(pos[head[v]], pos[v]));
        mn = min(mn, t.getmin(pos[head[v]], pos[v]));
        v = parent_[head[v]];
    }
    if(depth_[u] > depth_[v]) swap(u,v);
    if(u != v){
        mx = max(mx, t.getmax(pos[u]+1, pos[v]));
        mn = min(mn, t.getmin(pos[u]+1, pos[v]));
    }
    return {mx, mn};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    rei(i,1,m){
        cin >> e[i].u >> e[i].v >> e[i].l;
    }

    dsu.init(n);
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 1);
    sort(ord.begin(), ord.end(), [&](int a, int b){ return e[a].l > e[b].l; });

    rei(i,1,n){
        adj[i].clear();
        in_mst[i] = false;
        parent_[i] = 0;
    }

    for(int i : ord){
        if(dsu.unite(e[i].u, e[i].v)){
            in_mst[i] = true;
            adj[e[i].u].push_back(i);
            adj[e[i].v].push_back(i);
        }
    }

    curPos = 0;
    rei(i,1,n){
        if(parent_[i] == 0){
            depth_[i] = 0;
            wpar[i] = 0;
            dfs(i, 0);
            decompose(i, i);
        }
    }

    t.init(n);
    rei(i,1,n){
        t.upd(pos[i], wpar[i]);
    }

    long long ans = 0;
    rei(i,1,m){
        if(!in_mst[i]){
            auto pr = queryPath(e[i].u, e[i].v);
            long long a = max(pr.first, e[i].l);
            long long b = min(pr.second, e[i].l);
            ans = max(ans, a + b);
        }
    }

    cout << ans << "\n";
    return 0;
}

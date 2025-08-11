#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
#define fi first
#define se second
#define pb push_back
struct tuong { int l, r, y; ll v; };
int main(){
    if(fopen("WALLCLIM.INP","r")){
        freopen("WALLCLIM.INP","r",stdin);
        freopen("WALLCLIM.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int X;
    int n, m;
    cin>>X>>n>>m;
    vector<tuong> tuongs(n);
    vector<pair<int,int>> mt(m);
    vector<int> xsr, ysr;
    xsr.reserve(8 + 6*n + 6*m);
    ysr.reserve(8 + 6*n + 6*m);
    xsr.pb(X);
    xsr.pb(X-1);
    xsr.pb(X+1);
    ysr.pb(1);
    ysr.pb(0);
    ysr.pb(2);
    int minx = X, maxx = X;
    int miny = 1, maxy = 1;
    for(int i=0;i<n;i++){
        int l, r, y; ll v;
        cin >> l >> r >> y >> v;
        tuongs[i] = {l, r, y, v};
        xsr.pb(l-1);
        xsr.pb(l);
        xsr.pb(r);
        xsr.pb(r+1);
        ysr.pb(y-1);
        ysr.pb(y);
        ysr.pb(y+1);
        minx = min(minx, l);
        maxx = max(maxx, r);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        mt[i] = {a,b};
        xsr.pb(a-1);
        xsr.pb(a);
        xsr.pb(a+1);
        ysr.pb(b-1);
        ysr.pb(b);
        ysr.pb(b+1);
        minx = min(minx, a);
        maxx = max(maxx, a);
        miny = min(miny, b);
        maxy = max(maxy, b);
    }
    xsr.pb(minx - 1);
    xsr.pb(maxx + 1);
    ysr.pb(miny - 1);
    ysr.pb(maxy + 1);
    sort(xsr.begin(), xsr.end());
    xsr.erase(unique(xsr.begin(), xsr.end()), xsr.end());
    vector<int> xs2;
    xs2.reserve(xsr.size()*2 + 4);
    for(int v : xsr){
        xs2.pb(v);
        xs2.pb(v+1);
    }
    sort(xs2.begin(), xs2.end());
    xs2.erase(unique(xs2.begin(), xs2.end()), xs2.end());
    xsr.swap(xs2);
    sort(ysr.begin(), ysr.end());
    ysr.erase(unique(ysr.begin(), ysr.end()), ysr.end());
    vector<int> ys2;
    ys2.reserve(ysr.size()*2 + 4);
    for(int v : ysr){
        ys2.pb(v);
        ys2.pb(v+1);
    }
    sort(ys2.begin(), ys2.end());
    ys2.erase(unique(ys2.begin(), ys2.end()), ys2.end());
    ysr.swap(ys2);
    int nx = (int)xsr.size() - 1;
    int ny = (int)ysr.size() - 1;
    if(nx <= 0 || ny <= 0){
        for(int i=0;i<m;i++) cout << -1 << '\n';
        return 0;
    }
    auto get_xi = [&](int x)->int{
        int pos = int(upper_bound(xsr.begin(), xsr.end(), x) - xsr.begin()) - 1;
        if(pos < 0 || pos >= nx) return -1;
        return pos;
    };
    auto get_yi = [&](int y)->int{
        int pos = int(upper_bound(ysr.begin(), ysr.end(), y) - ysr.begin()) - 1;
        if(pos < 0 || pos >= ny) return -1;
        return pos;
    };
    vector<ll> tuong_up_fia((size_t)nx * ny, -1);
    auto idx2 = [&](int xi, int yi)->size_t{ return (size_t)yi * nx + xi; };
    for(const auto &w : tuongs){
        int yi = get_yi(w.y);
        if(yi < 0 || yi >= ny) continue;
        int li = int(lower_bound(xsr.begin(), xsr.end(), w.l) - xsr.begin());
        int ri = int(lower_bound(xsr.begin(), xsr.end(), w.r + 1) - xsr.begin());
        li = max(0, li);
        ri = min((int)xsr.size()-1, ri);
        for(int xi = li; xi <= ri-1; ++xi){
            tuong_up_fia[idx2(xi, yi)] = w.v;
        }
    }
    size_t S = (size_t)nx * ny;
    vector<ll> ds(S, INF);

    int sx_i = get_xi(X);
    int sy_i = get_yi(1);
    if(sx_i < 0 || sy_i < 0){
        for(int i=0;i<m;i++) cout << -1 << '\n';
        return 0;
    }
    auto id = [&](int xi, int yi)->size_t{ return idx2(xi, yi); };

    using P = pair<ll, size_t>;
    priority_queue<P, vector<P>, greater<P>> pq;
    ds[id(sx_i, sy_i)] = 0;
    pq.push({0, id(sx_i, sy_i)});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        ll d = cur.fi; size_t u = cur.se;
        if(d != ds[u]) continue;
        int xi = int(u % nx);
        int yi = int(u / nx);
        if(xi - 1 >= 0){
            ll fia = (ll)(xsr[xi] - xsr[xi-1]);
            size_t v = id(xi-1, yi);
            if(ds[v] > d + fia){
                ds[v] = d + fia;
                pq.push({ds[v], v});
            }
        }
        if(xi + 1 < nx){
            ll fia = (ll)(xsr[xi+1] - xsr[xi]);
            size_t v = id(xi+1, yi);
            if(ds[v] > d + fia){
                ds[v] = d + fia;
                pq.push({ds[v], v});
            }
        }
        if(yi - 1 >= 0){
            ll fia = (ll)(ysr[yi] - ysr[yi-1]);
            size_t v = id(xi, yi-1);
            if(ds[v] > d + fia){
                ds[v] = d + fia;
                pq.push({ds[v], v});
            }
        }
        if(yi + 1 < ny){
            ll dy = (ll)(ysr[yi+1] - ysr[yi]);
            ll fia = dy;
            if(dy == 1){
                ll wv = tuong_up_fia[idx2(xi, yi)];
                if(wv != -1) fia = wv;
            }
            size_t v = id(xi, yi+1);
            if(ds[v] > d + fia){
                ds[v] = d + fia;
                pq.push({ds[v], v});
            }
        }
    }

    for(const auto &t : mt){
        int tx = t.fi, ty = t.se;
        int xi = get_xi(tx), yi = get_yi(ty);

        ll ans = ds[id(xi, yi)];
        cout<<ans<<"\n";
    }
    return 0;
}

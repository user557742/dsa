#include <bits/stdc++.h>
using namespace std;
const int maxn=  101;
struct SegTree2D {
    int n, m;
    vector<vector<long long>> seg;
    vector<vector<long long>> a;
    SegTree2D(int _n=0, int _m=0) : n(_n),m(_m) {
        seg.assign(4 * n, vector<long long>(4 * m, LLONG_MIN));
        a.assign(n, vector<long long>(m, LLONG_MIN));
    }
    void build_y(int node_x, int lx, int rx, int node_y, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx) seg[node_x][node_y] = a[lx][ly];
            else seg[node_x][node_y] = max(seg[node_x*2][node_y], seg[node_x*2+1][node_y]);
        } else {
            int my = (ly + ry) / 2;
            build_y(node_x, lx, rx, node_y*2, ly, my);
            build_y(node_x, lx, rx, node_y*2+1, my+1, ry);
            seg[node_x][node_y] = max(seg[node_x][node_y*2], seg[node_x][node_y*2+1]);
        }
    }
    void build_x(int node_x, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(node_x*2, lx, mx);
            build_x(node_x*2+1, mx+1, rx);
        }
        build_y(node_x, lx, rx, 1, 0, m-1);
    }
    long long query_y(int node_x, int node_y, int ly, int ry, int qly, int qry) {
        if (qly > ry || qry < ly) return LLONG_MIN;
        if (qly <= ly && ry <= qry) return seg[node_x][node_y];
        int my = (ly + ry) / 2;
        return max(query_y(node_x, node_y*2, ly, my, qly, qry),
                   query_y(node_x, node_y*2+1, my+1, ry, qly, qry));
    }
    long long query_x(int node_x, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qlx > rx || qrx < lx) return LLONG_MIN;
        if (qlx <= lx && rx <= qrx) return query_y(node_x, 1, 0, m-1, qly, qry);
        int mx = (lx + rx) / 2;
        return max(query_x(node_x*2, lx, mx, qlx, qrx, qly, qry),
                   query_x(node_x*2+1, mx+1, rx, qlx, qrx, qly, qry));
    }
    void update_y(int node_x, int lx, int rx, int node_y, int ly, int ry, int x, int y, long long val) {
        if (ly == ry) {
            if (lx == rx) {
                seg[node_x][node_y] = max(seg[node_x][node_y], val);
            } else {
                seg[node_x][node_y] = max(seg[node_x*2][node_y], seg[node_x*2+1][node_y]);
            }
        } else {
            int my = (ly + ry) / 2;
            if (y <= my) update_y(node_x, lx, rx, node_y*2, ly, my, x, y, val);
            else update_y(node_x, lx, rx, node_y*2+1, my+1, ry, x, y, val);
            seg[node_x][node_y] = max(seg[node_x][node_y*2], seg[node_x][node_y*2+1]);
        }
    }
    void update_x(int node_x, int lx, int rx, int x, int y, long long val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) update_x(node_x*2, lx, mx, x, y, val);
            else update_x(node_x*2+1, mx+1, rx, x, y, val);
        }
        update_y(node_x, lx, rx, 1, 0, m-1, x, y, val);
    }
    long long query(int x1, int y1, int x2, int y2) {
        return query_x(1, 0, n-1, x1, x2, y1, y2);
    }
    void update(int x, int y, long long val) {
        update_x(1, 0, n-1, x, y, val);
    }
}g;
int n,m;
int a[maxn][maxn];
int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    g=SegTree2D(n,m);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g.update(i,j,a[i][j]);
    int q;cin>>q;
    while(q--){
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        cout<<g.query(x,y,u,v)<<"\n";
    }
    return 0;
}

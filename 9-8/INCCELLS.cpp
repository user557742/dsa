#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn  = 5e2+5;
int n,m,d;
int a[maxn][maxn];
typedef long long ll;
struct it2d {
    int n, m;
    vector<vector<ll>> seg;
    it2d(int _n=0, int _m=0) : n(_n), m(_m) {
        seg.assign(4 * max(1, n) + 5, vector<ll>(4 * max(1, m) + 5, LLONG_MIN));
    }
    ll qy(int nx, int ny, int ly, int ry, int qly, int qry) {
        if (qly > ry || qry < ly) return LLONG_MIN;
        if (qly <= ly && ry <= qry) return seg[nx][ny];
        int my = (ly + ry) / 2;
        return max(qy(nx, ny*2, ly, my, qly, qry),
                   qy(nx, ny*2+1, my+1, ry, qly, qry));
    }
    ll qx(int nx, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qlx > rx || qrx < lx) return LLONG_MIN;
        if (qlx <= lx && rx <= qrx) return qy(nx, 1, 1, m, qly, qry);
        int mx = (lx + rx) / 2;
        return max(qx(nx*2, lx, mx, qlx, qrx, qly, qry),
                   qx(nx*2+1, mx+1, rx, qlx, qrx, qly, qry));
    }
    void uy(int nx, int lx, int rx, int ny, int ly, int ry, int x, int y, ll val) {
        if (ly == ry) {
            if (lx == rx) seg[nx][ny] = max(seg[nx][ny], val);
            else seg[nx][ny] = max(seg[nx*2][ny], seg[nx*2+1][ny]);
            return;
        }
        int my = (ly + ry) / 2;
        if (y <= my) uy(nx, lx, rx, ny*2, ly, my, x, y, val);
        else uy(nx, lx, rx, ny*2+1, my+1, ry, x, y, val);
        seg[nx][ny] = max(seg[nx][ny*2], seg[nx][ny*2+1]);
    }
    void ux(int nx, int lx, int rx, int x, int y, ll val) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) ux(nx*2, lx, mx, x, y, val);
            else ux(nx*2+1, mx+1, rx, x, y, val);
        }
        uy(nx, lx, rx, 1, 1, m, x, y, val);
    }
    ll getans(int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) return LLONG_MIN;
        return qx(1, 1, n, x1, x2, y1, y2);
    }
    void upd(int x, int y, ll val) {
        if (x < 1 || x > n || y < 1 || y > m) return;
        ux(1, 1, n, x, y, val);
    }
};
struct o { int v,x,y; };
inline bool cmp(o &A,o &B){
    if (A.v != B.v) return A.v < B.v;
    if (A.x != B.x) return A.x < B.x;
    return A.y < B.y;
}
ll getmaxhcn(it2d &t, int u,int v,int w,int h){
    int rw = w/2;
    int rh = h/2;
    int bdx = u - rw, bdy = v - rh;
    int ktx = u + rw, kty = v + rh;
    bdx = max(bdx, 1); ktx = min(ktx, t.n);
    bdy = max(bdy, 1); kty = min(kty, t.m);
    return t.getans(bdx, bdy, ktx, kty);
}
int dp[maxn*maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen("INCCELLS.INP","r")){
        freopen("INCCELLS.INP","r",stdin);
        freopen("INCCELLS.OUT","w",stdout);
    }
    cin >> n >> m >> d;
    vector<o> s;
    s.reserve(n*m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int val; cin >> val;
            s.push_back({val,i,j});
        }
    }
    sort(s.begin(), s.end(), cmp);
    it2d t(n,m);
    int L = (int)s.size();
    vector<int> dp(L,1);
    for(int i=0; i<L; ){
        int j = i;
        while(j < L && s[j].v == s[i].v) ++j;
        for(int k=i; k<j; ++k){
            int w = 1;
            int h = 2*d+1;
            for(int ss=1; ss<=d; ++ss){
                ll q1 = getmaxhcn(t, s[k].x, s[k].y, w, h);
                if (q1 != LLONG_MIN) dp[k] = max(dp[k], (int)(q1 + 1));
                ll q2 = getmaxhcn(t, s[k].x, s[k].y, h, w);
                if (q2 != LLONG_MIN) dp[k] = max(dp[k], (int)(q2 + 1));
                w += 2; h -= 2;
            }
        }
        for(int k=i; k<j; ++k){
            t.upd(s[k].x, s[k].y, dp[k]);
        }
        i = j;
    }

    int ans = 0;
    for(int v : dp) ans = max(ans, v);
    cout << ans << "\n";
    return 0;
}

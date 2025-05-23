#include <iostream>
#include <vector>
#include <algorithm>
#define rei(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
typedef long long ll;

const int MAXN = 2005;
int n, m, l;
int a[MAXN][MAXN];
ll row_ps[MAXN][MAXN]; // prefix sum hàng
ll col1[MAXN], colm[MAXN]; // prefix sum cột 1 và m
pair<int,int> p[200005];

ll calc(int x1, int y1, int x2, int y2) {
    ll res = 1LL << 60;

    // Qua cột 1
    ll tmp = 0;
    if (y1 > 1) tmp += row_ps[x1][y1-1];
    if (x1 < x2) tmp += col1[x2] - col1[x1];
    else tmp += col1[x1] - col1[x2];
    if (y2 > 1) tmp += row_ps[x2][y2-1];
    res = min(res, tmp);

    // Qua cột m
    tmp = 0;
    if (y1 < m) tmp += row_ps[x1][m] - row_ps[x1][y1];
    if (x1 < x2) tmp += colm[x2] - colm[x1];
    else tmp += colm[x1] - colm[x2];
    if (y2 < m) tmp += row_ps[x2][m] - row_ps[x2][y2];
    res = min(res, tmp);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rei(i,1,n) rei(j,1,m) cin >> a[i][j];

    // Tính row prefix sum
    rei(i,1,n){
        row_ps[i][0] = 0;
        rei(j,1,m) row_ps[i][j] = row_ps[i][j-1] + a[i][j];
    }

    // Tính col prefix sum cho cột 1 và cột m
    col1[0] = colm[0] = 0;
    rei(i,1,n){
        col1[i] = col1[i-1] + a[i][1];
        colm[i] = colm[i-1] + a[i][m];
    }

    cin >> l;
    rei(i,1,l) cin >> p[i].first >> p[i].second;

    ll ans = a[1][1];
    int cx = 1, cy = 1;

    rei(i,1,l){
        int tx = p[i].first, ty = p[i].second;
        ans += calc(cx, cy, tx, ty);
        cx = tx; cy = ty;
    }

    cout << ans;
    return 0;
}

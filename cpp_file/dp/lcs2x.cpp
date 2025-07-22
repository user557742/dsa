#include <bits/stdc++.h>
using namespace std;

const int maxn = 1505;
int n, m;
int a[maxn], b[maxn];
int bit[maxn][maxn]; // 2D BIT to store max dp

// Hàm cập nhật giá trị max vào BIT
void update(int x, int y, int val) {
    for (int i = x; i < maxn; i += i & -i)
        for (int j = y; j < maxn; j += j & -j)
            bit[i][j] = max(bit[i][j], val);
}

// Truy vấn max từ (1,1) đến (x,y)
int get(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            res = max(res, bit[i][j]);
    return res;
}

// Reset BIT sau mỗi test
void reset(int n, int m) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            bit[i][j] = 0;
}
int dp[maxn][maxn];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int j = 1; j <= m; ++j) cin >> b[j];

    reset(n, m);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j]=max(dp[i][j],get(i,j)+1);
                update(i,j,dp[i][j]);
                res=max(res,dp[i][j]);
            }
        }
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) solve();
}

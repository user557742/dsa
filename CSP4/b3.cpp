#include <bits/stdc++.h>
using namespace std;

int n, l, r, k, m;
long long a[151], f[151][10001], g[151][10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    m = r - l + 1;

    for (int j = 0; j <= m; j++)
        for (int t = 0; t <= k; t++)
            f[j][t] = -(1LL<<60);
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        memcpy(g, f, sizeof f);
        for (int j = 1; j <= min(i, m); j++) {
            int pos = l + j - 1, c = abs(i - pos);
            for (int t = c; t <= k; t++)
                if (f[j-1][t-c] > -(1LL<<60))
                    g[j][t] = max(g[j][t], f[j-1][t-c] + a[i]);
        }
        memcpy(f, g, sizeof f);
    }

    long long ans = 0;
    for (int t = 0; t <= k; t++)
        ans = max(ans, f[m][t]);
    cout << ans;
    return 0;
}


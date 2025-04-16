#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n, m;
int d[maxn][maxn];
int s[maxn][maxn];
int f[maxn][maxn];
string a[maxn];

int getans(int u, int v, int x, int y) {
    return s[x][y] - s[x][v - 1] - s[u - 1][y] + s[u - 1][v - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen("POTENTIAL.INP","r")){
        freopen("POTENTIAL.INP","r",stdin);
        freopen("POTENTIAL.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] = " " + a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == '#') f[i][j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + f[i][j];
    for (int l1 = 1; l1 <= n; l1++)
        for (int r1 = 1; r1 <= m; r1++)
            for (int l2 = l1; l2 <= n; l2++)
                for (int r2 = r1; r2 <= m; r2++)
                    if (getans(l1, r1, l2, r2) == 0)
                        for (int i = l1; i <= l2; i++)
                            for (int j = r1; j <= r2; j++)
                                d[i][j]++;
    long long ds = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ds += d[i][j];
    cout << ds;
    return 0;
}

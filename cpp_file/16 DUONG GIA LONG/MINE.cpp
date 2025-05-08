#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
using ll = long long;

#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X first
#define Y second
#define sz(A) (int)A.size()
#define rei(i, l, r) for (int i = l; i <= r; i++)
#define red(i, r, l) for (int i = r; i >= l; i--)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int a[maxn], n;

int solve(int id) {
    int vis[105] = {0};
    vis[id] = 1;
    int l = id, r = id;
    int rad = 1, cnt = 1;

    while (1) {
        int nl = l, nr = r;
        red(i, l - 1, 1) {
            if (!vis[i] && a[l] - a[i] <= rad) {
                nl = i;
                vis[i] = 1;
                cnt++;
            } else if (a[l] - a[i] > rad) break;
        }
        rei(i, r + 1, n) {
            if (!vis[i] && a[i] - a[r] <= rad) {
                nr = i;
                vis[i] = 1;
                cnt++;
            } else if (a[i] - a[r] > rad) break;
        }
        if (nl == l && nr == r) break; 
        l = nl;
        r = nr;
        rad++;
    }
    return cnt;
}

int main() {
    faster;
    cin >> n;
    rei(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int res = 0;
    rei(i, 1, n) res = max(res, solve(i));
    cout << res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 1;

int n, a[maxn];

struct segtree {
    int s[4*maxn];
    void init() {
        for (int i = 0; i <= 4*n; i++) s[i] = 0;
    }
    void upd(int k, int x, int r = 1, int lo = 1, int hi = n) {
        if (lo == hi) {
            s[r] += x;
            return;
        }
        int mid = (lo + hi) / 2;
        if (k <= mid) upd(k, x, 2*r, lo, mid);
        else upd(k, x, 2*r+1, mid+1, hi);
        s[r] = max(s[2*r], s[2*r+1]);
    }
    int get(int u, int v, int r = 1, int lo = 1, int hi = n) {
        if (u > hi || v < lo) return 0;
        if (u <= lo && hi <= v) return s[r];
        int mid = (lo + hi) / 2;
        return max(get(u, v, 2*r, lo, mid), get(u, v, 2*r+1, mid+1, hi));
    }
} t;
int main() {
    if(fopen("MAJOURNUM.INP","r")){
        freopen("MAJOURNUM.INP","r",stdin);
        freopen("MAJOURNUM.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long ds = 0;
    for (int i = 1; i <= n; i++) {
        t.init();
        for (int j = i; j <= n; j++) {
            t.upd(a[j], 1);
            int ans = t.get(1, n);
            if (ans > (j - i + 1) / 2) ds++;
        }
    }
    cout << ds;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
#define mp make_pair
#define fi first
#define se second

int n, q;
int a[MAXN];

int sd(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    set<pair<int,int>> s;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 9) s.insert({i, a[i]});
    }

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            auto it = s.lower_bound({l, 0});
            while (it != s.end() && it->fi <= r) {
                int idx = it->fi;
                int val = sd(a[idx]);
                a[idx] = val;
                it = s.erase(it);
                if (val > 9) s.insert({idx, val});
            }
        } else {
            int x;
            cin >> x;
            cout << a[x] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) solve();
}

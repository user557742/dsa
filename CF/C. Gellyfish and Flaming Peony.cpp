#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int g = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            g = __gcd(g, a[i]);
        }

        int count_g = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == g) count_g++;
        }

        if (count_g > 0) {
            cout << (n - count_g) << '\n';
            continue;
        }

        unordered_set<int> vals(a.begin(), a.end());
        vector<bool> visited(5001, false);
        queue<pair<int, int>> q;

        for (int v : vals) {
            visited[v] = true;
            q.push({v, 0});
        }

        int dist_to_g = -1;

        while (!q.empty()) {
            auto [v, d] = q.front();
            q.pop();
            if (v == g) {
                dist_to_g = d;
                break;
            }

            for (int w : vals) {
                int u = __gcd(v, w);
                if (!visited[u]) {
                    visited[u] = true;
                    q.push({u, d + 1});
                    if (u == g) {
                        dist_to_g = d + 1;
                        while (!q.empty()) q.pop(); 
                        break;
                    }
                }
            }
        }

        cout << (dist_to_g + (n - 1)) << '\n';
    }

    return 0;
}
    
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, H;
    cin >> n >> H;
    vector<int> h(n), w(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> w[i] >> s[i];
    }

    int max_safety = -1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int total_h = 0;
        vector<pair<int, int>> cows; // (weight, strength)
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                total_h += h[i];
                cows.emplace_back(w[i], s[i]);
            }
        }
        if (total_h < H) continue;

        // Sort by (strength + weight) in descending order
        sort(cows.begin(), cows.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return (a.second + a.first) > (b.second + b.first);
        });

        int sum_above = 0;
        int current_min = INT_MAX;
        bool valid = true;
        // Process from top to bottom (reverse order)
        for (auto it = cows.rbegin(); it != cows.rend(); ++it) {
            int weight = it->first;
            int strength = it->second;
            if (strength < sum_above) {
                valid = false;
                break;
            }
            int s_val = strength - sum_above;
            if (s_val < current_min) {
                current_min = s_val;
            }
            sum_above += weight;
        }
        if (valid) {
            max_safety = max(max_safety, current_min);
        }
    }

    if (max_safety == -1) {
        cout << "Mark is too tall" << endl;
    } else {
        cout << max_safety << endl;
    }

    return 0;
}
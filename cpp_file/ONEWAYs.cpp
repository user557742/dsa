#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

int n, m, p, timeDFS;
vector<pair<int, int>> adj[MAX];
vector<pair<int, int>> edges;
vector<int> disc, low;
vector<bool> isBridge;
vector<char> res;

void tarjan(int u, int parent) {
    disc[u] = low[u] = ++timeDFS;
    for (auto &[v, idx] : adj[u]) {
        if (v == parent) continue;
        if (!disc[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                isBridge[idx] = true;
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }

    disc.assign(n + 1, 0);
    low.assign(n + 1, 0);
    isBridge.assign(m, false);
    timeDFS = 0;

    for (int u = 1; u <= n; ++u) {
        if (!disc[u]) {
            tarjan(u, -1);
        }
    }

    cin >> p;
    vector<pair<int, int>> req(p);
    for (int i = 0; i < p; ++i) {
        cin >> req[i].first >> req[i].second;
    }

    res.assign(m, 'B');
    for (int i = 0; i < m; ++i) {
        if (isBridge[i]) {
            res[i] = 'R'; // Mặc định gán 'R', cần kiểm tra yêu cầu để điều chỉnh
        }
    }

    // Kiểm tra các yêu cầu để điều chỉnh hướng cầu
    // (Phần này cần thêm xử lý đồ thị SCC và BFS/DFS để kiểm tra đường đi)
    // Ở đây tạm thời giữ nguyên cách gán 'R' cho cầu và 'B' cho cạnh thường

    for (char c : res) {
        cout << c;
    }
    cout << '\n';

    return 0;
}
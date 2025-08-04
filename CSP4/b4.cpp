#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int nA, nB, m;
vector<int> adj[N];
int match[N], vis[N], timer;

bool dfs(int u) {
    if (vis[u] == timer) return false;
    vis[u] = timer;
    for (int v : adj[u]) {
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> nA >> nB >> m;

    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        // Kết nối A -> B
        adj[u].push_back(v + nA); // dồn B sang index > nA để phân biệt
    }

    int res = 0;
    for (int u = 1; u <= nA; ++u) {
        ++timer;
        if (dfs(u)) ++res;
    }

    cout << res << '\n'; // chính là size của maximum matching = số thao tác tối thiểu
}

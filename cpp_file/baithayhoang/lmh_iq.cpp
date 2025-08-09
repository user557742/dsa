#include <bits/stdc++.h>
using namespace std;

const int MAXV = 400005;
struct Edge {
    int u, v, cap, flow;
    Edge(int _u, int _v, int _cap) : u(_u), v(_v), cap(_cap), flow(0) {}
};

vector<Edge> edges;
vector<int> adj[MAXV];
int d[MAXV], cl[MAXV], vid = 1;

void adde(int u, int v, int c) {
    adj[u].push_back(edges.size());
    edges.emplace_back(u, v, c);
    adj[v].push_back(edges.size());
    edges.emplace_back(v, u, 0);
}

bool bfs(int s, int t) {
    for(int i = 0; i <= t; i++) d[i] = INT_MAX;
    d[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int ei: adj[u]) {
            auto &E = edges[ei];
            if(E.flow < E.cap && d[E.v] > d[u] + 1) {
                d[E.v] = d[u] + 1;
                q.push(E.v);
            }
        }
    }
    return d[t] < INT_MAX;
}

int dfs(int u, int f, int t) {
    if(u == t) return f;
    if(cl[u] == vid) return 0;
    cl[u] = vid;
    for(int ei: adj[u]) {
        auto &E = edges[ei];
        if(E.flow < E.cap && d[E.v] == d[u] + 1) {
            int pushed = dfs(E.v, min(f, E.cap - E.flow), t);
            if(pushed) {
                E.flow += pushed;
                edges[ei^1].flow -= pushed;
                return pushed;
            }
        }
    }
    return 0;
}

int dinic(int s, int t) {
    int maxflow = 0;
    while(bfs(s, t)) {
        vid++;
        while(int pushed = dfs(s, INT_MAX, t)) {
            maxflow += pushed;
            vid++;
        }
    }
    return maxflow;
}

int a[MAXV], b[MAXV];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int SRC   = 0;
    int LEFT  = 1;
    int RIGHT = n + 1;
    int SINK  = 2*n + 1;
    for(int i = 1; i <= n; i++)
        adde(SRC, LEFT + i - 1, 1);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i] >= b[j])
                adde(LEFT + i - 1, RIGHT + j - 1, 1);
        }
    }
    for(int i = 1; i <= n; i++){
        long long bi2 = 1LL * b[i] * b[i];
        for(int j = 1; j <= n; j++){
            if(bi2 >= 2LL * a[j] * a[j])
                adde(LEFT + j - 1, RIGHT + i - 1, 1);
        }
    }
    for(int j = 1; j <= n; j++)
        adde(RIGHT + j - 1, SINK, 1);
    dinic(SRC, SINK);
    vector<int> ans(n+1, 0);
    for(int ei = 0; ei < (int)edges.size(); ei += 2){
        auto &E = edges[ei];
        if(E.flow == 1
           && E.u >= LEFT && E.u < LEFT + n
           && E.v >= RIGHT && E.v < RIGHT + n)
        {
            int sq = E.u - LEFT + 1;
            int cr = E.v - RIGHT + 1;
            ans[sq] = cr;
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] <<" ";
    }
    return 0;
}

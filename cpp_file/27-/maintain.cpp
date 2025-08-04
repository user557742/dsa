#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
const int LG   = 18;               // vì 2*maxn ≤ 2e5, log2(2e5)<18

#define rei(i,a,b) for(int i=(a); i<=(b); i++)

int n, p, t, m;
vector<int> adj[maxn];
int pos[maxn], depth[maxn], id = 0;
pair<int,int> st[LG+1][2*maxn];

void dfs(int u, int fa){
    pos[u] = ++id;
    st[0][id] = {depth[u], u};
    for(int v: adj[u]) if(v != fa){
        depth[v] = depth[u] + 1;
        dfs(v, u);
        st[0][++id] = {depth[u], u};
    }
}

void build(){
    int M = id;
    rei(k,1,LG){
        int len = 1<<k;
        rei(i,1, M - len + 1){
            st[k][i] = min(st[k-1][i],
                           st[k-1][i + (1<<(k-1))]);
        }
    }
}

int lca(int u, int v){
    int L = pos[u], R = pos[v];
    if(L > R) swap(L,R);
    int span = R - L + 1;
    int k = __lg(span);
    return min(st[k][L], st[k][R - (1<<k) + 1]).second;
}

int calc(int u, int v){
    int w = lca(u, v);
    int up   = depth[u] - depth[w];   
    int down = depth[v] - depth[w];    
    int D = up + down;                 
    int stops_up   = (up   > p ? ( (up   + p - 1) / p ) - 1 : 0);
    int stops_down = (down > p ? ( (down + p - 1) / p ) - 1 : 0);
    int switch_rest = (up > 0 && down > 0) ? 1 : 0;

    int total_stops = stops_up + stops_down + switch_rest;
    return D + total_stops * t;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> t;
    rei(i,1,n-1){
        int u,v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 0);
    build();

    cin >> m;
    while(m--){
        int u,v; 
        cin >> u >> v;
        cout << calc(u,v) << "\n";
    }
    return 0;
}

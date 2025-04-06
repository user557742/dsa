#include <bits/stdc++.h>
using namespace std;
 
// -----------------------------
// 1. Compute SCC for requirement graph (using Tarjan)
 
int n, m, p;
vector<vector<int>> reqG; // requirement graph (from p pairs)
 
// Tarjan globals
int timer = 0;
vector<int> low, disc;
vector<bool> inStack;
stack<int> st;
int sccCount = 0;
vector<int> comp; // comp[v] = SCC id of v

void tarjanDFS(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;
    for (int v : reqG[u]) {
        if(disc[v] == 0) {
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        } else if(inStack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }
    if(low[u] == disc[u]) {
        // found SCC root
        while (true) {
            int v = st.top();
            st.pop();
            inStack[v] = false;
            comp[v] = sccCount;
            if(v == u) break;
        }
        sccCount++;
    }
}
 
// -----------------------------
// 2. Topological order and DP on DAG of components
 
vector<vector<int>> dag; // DAG of SCCs from requirement edges
vector<int> indeg;
vector<int> topo;      // topologically sorted list (SCC ids)
vector<int> order;     // order[scc] = index in topo (0-indexed)
vector<int> dp;        // dp[scc] = max order reachable from scc (including itself)
 
// Compute topological sort on DAG
void computeTopo() {
    int sz = sccCount;
    indeg.assign(sz, 0);
    for (int u = 0; u < sz; u++){
        for (int v : dag[u])
            indeg[v]++;
    }
    queue<int> q;
    for (int u = 0; u < sz; u++){
        if(indeg[u]==0)
            q.push(u);
    }
    topo.clear();
    while(!q.empty()){
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : dag[u]){
            indeg[v]--;
            if(indeg[v]==0)
                q.push(v);
        }
    }
    // assign order and initialize dp
    order.assign(sz, -1);
    dp.assign(sz, -1);
    for (int i = 0; i < (int)topo.size(); i++){
        order[topo[i]] = i;
        dp[topo[i]] = i; // at least itself
    }
    // Process in reverse topological order
    for (int i = topo.size()-1; i >= 0; i--){
        int u = topo[i];
        for (int v : dag[u]){
            dp[u] = max(dp[u], dp[v]);
        }
    }
}
 
// -----------------------------
// 3. Bridge-finding on the undirected graph built on SCCs (H')
// We build H' using unique comparable pairs (u,v)
 
struct Edge {
    int u, v;
    int id; // id for identification (for later marking as bridge)
};
 
int timeDfs = 0;
vector<int> tin, lowB;
vector<vector<pair<int,int>>> H; // H[u] = { {v, edge_id} }
vector<bool> isBridge; // for each unique edge in H'
 
void dfsBridge(int u, int parentEdge) {
    tin[u] = lowB[u] = ++timeDfs;
    for(auto &p : H[u]){
        int v = p.first, edgeId = p.second;
        if(edgeId == parentEdge) continue;
        if(tin[v] == 0){
            dfsBridge(v, edgeId);
            lowB[u] = min(lowB[u], lowB[v]);
            if(lowB[v] > tin[u])
                isBridge[edgeId] = true;
        } else {
            lowB[u] = min(lowB[u], tin[v]);
        }
    }
}
 
// -----------------------------
// 4. Main – process roads and requirements
struct Road {
    int a, b; // endpoints (1-indexed cities)
};
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    vector<Road> roads(m);
    for (int i = 0; i < m; i++){
        cin >> roads[i].a >> roads[i].b;
        // note: roads are two-way
    }
    cin >> p;
    // Build requirement graph (cities: 1-indexed -> convert to 0-indexed)
    reqG.assign(n, vector<int>());
    for (int i = 0; i < p; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        reqG[x].push_back(y);
    }
    
    // Compute SCC on requirement graph
    disc.assign(n, 0);
    low.assign(n, 0);
    inStack.assign(n, false);
    comp.assign(n, -1);
    for (int i = 0; i < n; i++){
        if(disc[i] == 0)
            tarjanDFS(i);
    }
    
    // Build DAG of SCCs from requirement edges
    dag.assign(sccCount, vector<int>());
    {
        // use set to avoid duplicate edges
        vector<unordered_set<int>> dagSet(sccCount);
        for (int u = 0; u < n; u++){
            for (int v : reqG[u]){
                if(comp[u] != comp[v])
                    dagSet[comp[u]].insert(comp[v]);
            }
        }
        for (int u = 0; u < sccCount; u++){
            for (int v : dagSet[u])
                dag[u].push_back(v);
        }
    }
    computeTopo();
    
    // Prepare output array (default 'B')
    vector<char> ans(m, 'B');
 
    // For each road, decide if its endpoints (in terms of SCC) are comparable.
    // If comp(a)==comp(b) then output remains 'B'
    // Otherwise, check if there is a forced order:
    // if order[cu] < order[cv] and dp[cu] >= order[cv], then forced direction is from comp(a)==cu to comp(b)==cv.
    // Similarly check the reverse.
    // For roads that are "comparable", we record them for potential forced checking via bridge.
    struct CompEdge {
        int u, v; // u and v are the two SCC ids (the ordered pair: lower, higher)
        int idx;  // original road index
        // candidate: if the forced orientation is from lower comp to higher comp.
        // For road i = (a,b): if comp[a]==lower then candidate means a->b (i.e. output 'R'),
        // else if comp[b]==lower then candidate means b->a (i.e. output 'L').
        bool candidateFromA; // true if a is in the lower component.
    };
    vector<CompEdge> compEdges;
 
    for (int i = 0; i < m; i++){
        int a = roads[i].a - 1, b = roads[i].b - 1;
        int ca = comp[a], cb = comp[b];
        if(ca == cb) continue; // same component: not forced
        bool comparable = false;
        bool candidateFromA = false;
        int lower, higher;
        // check if ca->cb is forced by requirements:
        if(order[ca] < order[cb] && dp[ca] >= order[cb]){
            comparable = true;
            lower = ca; higher = cb;
            // forced orientation: from lower to higher.
            candidateFromA = (ca == comp[a]);
        } else if(order[cb] < order[ca] && dp[cb] >= order[ca]){
            comparable = true;
            lower = cb; higher = ca;
            candidateFromA = (cb == comp[a]);
        }
        if(comparable){
            // record this road as comparable candidate.
            compEdges.push_back({lower, higher, i, candidateFromA});
        }
    }
 
    // For each comparable road, if there are multiple roads connecting the same unordered pair,
    // then none of them is forced (because the connectivity can be achieved by an alternative).
    // We'll group by (lower, higher).
    // Also build an undirected graph H' on super-vertices (SCCs) with unique edge between lower and higher.
    map<pair<int,int>, vector<int>> group; // key -> indices in compEdges
    for (int i = 0; i < (int)compEdges.size(); i++){
        auto &ce = compEdges[i];
        pair<int,int> key = {ce.u, ce.v};
        group[key].push_back(i);
    }
 
    // Build H' (unique edges) among SCCs for those keys
    int Hedges = group.size(); // number of unique edges
    // assign each unique edge an id (0-indexed)
    // We'll build an undirected graph on nodes 0..sccCount-1 (only those nodes that appear, but can use full range)
    H.assign(sccCount, vector<pair<int,int>>());
    // Map from key to edge id.
    map<pair<int,int>, int> edgeIdMap;
    int eid = 0;
    for(auto &pr : group){
        pair<int,int> key = pr.first;
        edgeIdMap[key] = eid;
        // add undirected edge in H
        H[key.first].push_back({key.second, eid});
        H[key.second].push_back({key.first, eid});
        eid++;
    }
    // Prepare bridge marker for each unique edge
    isBridge.assign(eid, false);
    tin.assign(sccCount, 0);
    lowB.assign(sccCount, 0);
    timeDfs = 0;
    for (int i = 0; i < sccCount; i++){
        if(tin[i] == 0)
            dfsBridge(i, -1);
    }
 
    // For each comparable road, if the unique edge it belongs to has multiplicity > 1, then it is not forced.
    // Otherwise, if the unique edge is a bridge then the candidate orientation is forced.
    for(auto &pr : group){
        pair<int,int> key = pr.first;
        vector<int> &indices = pr.second;
        int freq = indices.size();
        int id = edgeIdMap[key];
        if(freq > 1) {
            // not forced: leave as 'B'
            continue;
        }
        // freq == 1: check if H' edge is a bridge
        if(isBridge[id]) {
            // forced edge: mark the corresponding road with candidate orientation.
            int compEdgeIndex = indices[0];
            CompEdge &ce = compEdges[compEdgeIndex];
            int roadIdx = ce.idx;
            // candidateFromA==true means forced orientation is from a to b ('R')
            ans[roadIdx] = ce.candidateFromA ? 'R' : 'L';
        }
    }
 
    // For roads that are not comparable or not forced, ans remains 'B'
    // Output the answer string (in the order of input roads)
    for (char c : ans) cout << c;
    cout << "\n";
    
    return 0;
}

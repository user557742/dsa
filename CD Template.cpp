#include <bits/stdc++.h>
#define maxn 200001

using namespace std;

int n;
vector<int> adj[maxn];
int Tsize;
int sz[maxn];
int par[maxn];

void Resubsize ( int u, int p ) {
    ++Tsize;
    sz[u] = 1;
    for ( int v : adj[u] )
        if ( v != p && !par[v] ) {
            Resubsize ( v, u );
            sz[u] += sz[v];
        }
}

int GetCentroid ( int u, int p ) {
    for ( int v : adj[u] )
        if ( v != p && !par[v] && sz[v] > Tsize / 2 )
            return GetCentroid ( v, u );
    return u;
}

void Decompose ( int u, int p ) {
    Tsize = 0;
    Resubsize ( u, p );
    int centroid = GetCentroid ( u, p );
    if ( p == 0 )
        par[centroid] = centroid;
    else
        par[centroid] = p;
    for ( int v : adj[centroid] )
        if ( v != p && !par[v] )
            Decompose ( v, u );
}

int main() {
    // Input
    cin >> n;
    for ( int i = 1; i < n; ++i ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back ( v );
        adj[v].push_back ( u );
    }

    // Ceontroid Decompose
    Decompose ( 1, 0 );
}

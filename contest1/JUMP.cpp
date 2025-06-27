#include <bits/stdc++.h>
using namespace std;
int n,k;
const int maxn = 2e5+1;
int a[maxn];
int x[maxn];vector<int> adj[maxn];
void dfs(int u){
    x[u]=1;
    for(int v:adj[u]) if(!x[v]) dfs(v);
}
int main(){
    if(fopen("JUMP.INP","r")){
        freopen("JUMP.INP","r",stdin);
        freopen("JUMP.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
}
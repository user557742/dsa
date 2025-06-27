#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
typedef long long ll;
int n;vector<int> adj[maxn];
struct E{
    int u,v;
    ll l;
    E(int _u=0,int _v=0,ll _l=0) : u(_u) , v(_v),l(_l) {}
} e[maxn];
ll d[maxn];
int pre[maxn];
void dfssub1(int u,int dad,int x,int k){
    pre[u]=dad;
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        ll l=e[i].l;
        if(u==x||v==x) l*=k; 
        if(v!=dad){
            d[v]=d[u]+l;
            dfs(v,u);
        }
    }
}
void solve(int x,int k){
    memset(d,0,sizeof(d));
    dfssub1(1,0,x,k);
    ll ds=0;
    int c=0;
    rei(i,2,n) {
        if(ds<d[i]){
            ds=d[i];
            c=i;
        }
    }
    memset(d,0,sizeof(d));
    ds=0;
    dfssub1(c,0,x,k);
    rei(i,1,n) {
        ds=max(ds,d[i]);
    }
    cout<<ds<<"\n";
}
int main(){
    cin>>n;
    rei(i,1,n-1){
        cin>>e[i].u>>e[i].v>>e[i].l;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    int q;cin>>q;
    while(q--){
        int x
    }
}
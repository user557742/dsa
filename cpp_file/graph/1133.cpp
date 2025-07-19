#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
typedef int64_t ll;
ll d[maxn];
int sz[maxn];
vector<int> adj[maxn];
int n;
void dfs(int u,int dad){
	d[u]=0;
	sz[u]=1;
	for(int v:adj[u]) if(v!=dad){
		dfs(v,u);
		sz[u]+=sz[v];
		d[u]+=d[v]+sz[v];
	}
}
ll ans[maxn];
void calc(int u,int dad){
	ans[u]=d[u];
	for(int v:adj[u]) if(v!=dad){
		ll du=d[u],dv=d[v];
		int szu=sz[u],szv=sz[v];
		d[u]-=d[v]+sz[v];
		sz[u]-=sz[v];
		d[v]+=d[u]+sz[u];
		sz[v]+=sz[u];
		calc(v,u);
		d[u]=du;d[v]=dv;
		sz[u]=szu;sz[v]=szv;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	calc(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
vector<int> adj[maxn];
int st[19][maxn];
int depth[maxn];
void dfs(int u,int dad){
	st[0][u]=dad;
	for(int x=1;x<19;x++) st[x][u]=st[x-1][st[x-1][u]];
	for(int v:adj[u]) if(v!=dad){
		depth[v]=depth[u]+1;
		dfs(v,u);	
	} 
}
int anc(int u,int k){
	int cnt=0;
	for(int i=19;i>=0;i--){
		if((1<<i)<=k){
			k-=(1<<i);
			u=st[i][u];
		}
	}
	return u;
}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	int dis=depth[v]-depth[u];
	for(int i=19;i>=0;i--){
		if(dis>=(1<<i)){
			dis-=(1<<i);
			v=st[i][v];
		}
	}
	if(v==u) return u;
	for(int i=19;i>=0;i--){
		if(st[i][v]!=st[i][u]){
			u=st[i][u];
			v=st[i][v];
		}
	}
	return st[0][u];
}
int n;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	dfs(1,0);
	int q;cin>>q;
	while(q--){
		int u,k;cin>>u>>k;
		cout<<lca(u,k)<< " \n";
	}	 	
}


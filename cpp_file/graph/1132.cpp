#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn =2e5+1;
int d[maxn],d1[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
	for(int v:adj[u]) if(v!=dad){
		dfs(v,u);
		if(d[u]<d[v]+1){
			d1[u]=d[u];
			d[u]=d[v]+1;
		}
		else d1[u]=max(d[v]+1,d1[u]);  
	}
}
int ans[maxn];
void calc(int u,int dad){
	for(int v:adj[u]) if(v!=dad){
		int d1v=d1[v],dv=d[v];
		int d1u=d1[u],du=d[u];
		if(d[v]+1==d[u]){
			if(d1[u]+1>d[v]){
				d1[v]=d[v];
				d[v]=d1[u]+1;
			}
			else if(d1[u]+1>d1[v]) d1[v]=d1[u]+1;
		}
		else{
			if(d[u]+1>d[v]){
				d1[v]=d[v];
				d[v]=d[u]+1;
			}
			else d1[v]=max(d1[v],d[u]+1);
		}
		ans[v]=d[v];
		calc(v,u);
		d[v]=dv;d[u]=du;
		d1[v]=d1v;d1u=d1[u];
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1,0);
	ans[1]=d[1];
	calc(1,0);
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
}

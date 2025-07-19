#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
vector<int> adj[maxn];
int n;
typedef long long ll;
bool ok[maxn];
ll nhan[maxn];
void dfs(int u,int dad){
	
	nhan[u]=1;
	ll lim=0;
	for(int v:adj[u]) if(v!=dad){
		dfs(v,u);
		lim=max(nhan[v],lim);
	}
	lim++;
	for(int i=1;i<=lim;i++){
		ok[i]=0;
	}
	int ds=0;
	for(int v:adj[u]) if(v!=dad){
		ok[nhan[v]]=1;
	}
	for(int i=1;i<=lim;i++){
		if(ok[i]==0){
			ds=i;
			break;
		}
	}
	nhan[u]=ds;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int r=0;
	ll ds=1e18;
	for(int i=1;i<=n;i++){
		dfs(i,0);
		ll ans=0;
		for(int j=1;j<=n;j++){
			ans+=nhan[j];
		}
		if(ds>ans){
			ds=ans;
			r=i;
		}
	}
	dfs(r,0);
	cout<<ds<<"\n";
	for(int i=1;i<=n;i++) cout<<nhan[i]<<"\n"; 
}

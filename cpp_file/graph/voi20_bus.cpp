#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 50001;
int n,m,s,t;
struct E{
	int c=0,u=0,v=0,l=0;
} e[maxn];
vector<int> adj[maxn];
bool vis[maxn];
bool fa(int a){
	rei(i,1,n) vis[i]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i:adj[u]){
			int v=(e[i].u==u) ? e[i].v : e[i].u;
			int l=(e[i].c==2) ? 0 : e[i].l;
			if(vis[v]==0){
				if(a>=l){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return vis[t];
}
int fla(int x){
	int lo=0,hi=x;
	if(fa(lo)){
		return lo;	
	}
	if(!fa(hi)){
		return -1e9;
	}
	while(lo+1<hi){
		int mid=(lo+hi)/2;
		if(fa(mid)) hi=mid;
		else lo=mid;
	}
	return hi;
}
bool f(int x){
	int a=fla(x);
	if(a==-1e9) return 0;
	int b=x-a;
	rei(i,1,n) vis[i]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i:adj[u]){
			int v=(e[i].u==u) ? e[i].v : e[i].u;
			int l=(e[i].c==1) ? 0 : e[i].l;
			if(vis[v]==0){
				if(b>=l){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return vis[t];
}
void bs(){
	int lo=0,hi=1;
	while(!f(hi)){
		lo=hi;
		hi*=2;
	}
	if(f(lo)){
		cout<<lo;
		return ;
	}
	while(lo+1<hi){
		int mid=(lo+hi)/2;
		if(f(mid)) hi=mid;
		else lo=mid;
	}
	cout<<hi;
}
int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>m>>s>>t;
	rei(i,1,m) cin>>e[i].c>>e[i].u>>e[i].v>>e[i].l;
	rei(i,1,m){
		adj[e[i].u].push_back(i);
		adj[e[i].v].push_back(i);
	}
	bs();
	return 0;
}


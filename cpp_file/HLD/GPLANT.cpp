#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,a[maxn];
typedef long long ll;
vector<int> adj[maxn];
struct node{
    ll s=0,lz=0;
    node(ll _s=0,ll _lz=0) : s(_s),lz(_lz){}    
};
struct It{
    node g[4*maxn];
    void down(int r,int lo,int hi){
        int mid=(lo+hi)/2;
        g[2*r].s+=g[r].lz*(mid-lo+1);
        g[2*r+1].s+=g[r].lz*(hi-mid);
        g[2*r+1].lz+=g[r].lz;
        g[2*r].lz+=g[r].lz;
        g[r].lz=0;
    }
    void upd(int u,int v,ll x,int r=1,int lo=1,int hi=n){
        if(u>hi||lo>v) return;
        if(u<=lo&&hi<=v){
            g[r].s+=x*(hi-lo+1);
            g[r].lz+=x;
            
            return ;
        }
        int mid=(lo+hi)/2;
        down(r,lo,hi);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        g[r].s=g[2*r].s+g[2*r+1].s;
    }
    ll getans(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||lo>v) return 0;
        if(u<=lo&&hi<=v){
            return g[r].s;
        }
        int mid=(lo+hi)/2;
        down(r,lo,hi);
        return getans(u,v,2*r,lo,mid)+getans(u,v,2*r+1,mid+1,hi);
    }
}t;
/*struct Itfake{
    ll s[maxn];
    void upd(int u,int v,int x){
        for(int i=u;i<=v;i++) s[i]+=x;
    }
    ll getansans(int u,int v){
        ll ds=0;
        for(int i=u;i<=v;i++) ds+=s[i];
        return ds;
    }
} t;*/
int depth[maxn],heavy[maxn],head[maxn];
int sz[maxn],pos[maxn],id=0,pre[maxn];
void dfs(int u){
	sz[u]=1;
	int msz=1,cmax=0;
	for(int v:adj[u]) if(v!=pre[u]){
		pre[v]=u;
		dfs(v);
		if(msz<sz[v]){
			msz=sz[v];
			cmax=v;
		}
		sz[u]+=sz[v];
	}
	heavy[u]=cmax;
}
void hld(int u,int h){
	head[u]=h;
	if(u!=h) depth[u]=depth[h];
	else depth[u]=depth[pre[u]]+1;
	pos[u]=++id;
	if(heavy[u]!=0) hld(heavy[u],h);
	for(int v:adj[u]) if(v!=pre[u]&&v!=heavy[u]){
		hld(v,v);
	}
}
void truyvan1(int u,int v){
    if(depth[u]>depth[v]) swap(u,v);
	while(depth[v]>depth[u]){
		t.upd(pos[head[v]],pos[v],1);
		v=pre[head[v]];
	}
	while(head[u]!=head[v]){
		t.upd(pos[head[u]],pos[u],1);
		t.upd(pos[head[v]],pos[v],1);
		v=pre[head[v]];
		u=pre[head[u]];
	}
	if(pos[u]<=pos[v]) t.upd(pos[u]+1,pos[v],1);
	else t.upd(pos[v]+1,pos[u],1);
}
void truyvan2(int u,int v){
    ll ds=0;
	if(depth[u]>depth[v]) swap(u,v);
	while(depth[v]>depth[u]){
		ds+=t.getans(pos[head[v]],pos[v]);
		v=pre[head[v]];
	}
	while(head[u]!=head[v]){
		ds+=t.getans(pos[head[u]],pos[u])+t.getans(pos[head[v]],pos[v]);
		v=pre[head[v]];
		u=pre[head[u]];
	}
	if(pos[u]<=pos[v]) ds+=t.getans(pos[u]+1,pos[v]);
	else ds+=t.getans(pos[v]+1,pos[u]);
	cout<<ds<<"\n";
}
int m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    hld(1,1);
    t.upd(1,n,0);
    while(m--){
        char l;cin>>l;
        if(l=='Q'){
            int u,v;cin>>u>>v;
            truyvan2(u,v);
        }
        else{
            int u,v;cin>>u>>v;
            truyvan1(u,v);
        }
    }
}
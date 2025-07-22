#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int vis[maxn];
int n,m,q;
vector<int> adj[maxn];
struct E{
    int u=0,v=0,l=0;
} e[maxn];
vector<int> ke[maxn];
struct dsu{
    int sz[maxn];
    int pre[maxn];
    void ms(int u){
        sz[u]=1;
        pre[u]=u;
    }
    int find(int u){
        if(u==pre[u]) return u;
        int p=find(pre[u]);
        pre[u]=p;
        return p;
    }
    void noi(int u,int v){
        u=find(u);
        v=find(v);
        if(v!=u){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
    bool lt(int u,int v){
        u=find(u);
        v=find(v);
        return u==v;
    }
}t;
bool cmp(E u,E v){
    return u.l<v.l;
}
struct it{
    int s[maxn];
    void upd(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi) {
            s[r]=x;
            return;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=max(s[2*r],s[2*r+1]);
    }   
    int get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||v<lo) return -1e9;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return max(get(u,v,2*r,lo,mid),get(u,v,2*r+1,mid+1,hi));
    }
}tree;
int depth[maxn],heavy[maxn],head[maxn];
int sz[maxn],pos[maxn],id=0,pre[maxn];
void dfs(int u){
	sz[u]=1;
	int msz=1,cmax=0;
	for(int i:ke[u]){
        int v=(e[i].u==u) ? e[i].v :e[i].u;
        if(v!=pre[u]){
            pre[v]=u;
            dfs(v);
            if(msz<sz[v]){
                msz=sz[v];
                cmax=v;
            }
            sz[u]+=sz[v];
        }
    }
	heavy[u]=cmax;
}
void hld(int u,int h){
	head[u]=h;
	if(u!=h) depth[u]=depth[h];
	else depth[u]=depth[pre[u]]+1;
	pos[u]=++id;
	if(heavy[u]!=0) hld(heavy[u],h);
	for(int i:ke[u]){
        int v=(e[i].u==u) ? e[i].v :e[i].u;
        if(v!=pre[u]&&v!=heavy[u]) hld(v,v);
    }
}
int calc(int u,int v){
    int ds=0;
	if(depth[u]>depth[v]) swap(u,v);
	while(depth[v]>depth[u]){
		ds=max(tree.get(pos[head[v]],pos[v]),ds);
		v=pre[head[v]];
	}
	while(head[u]!=head[v]){
		ds=max(tree.get(pos[head[v]],pos[v]),ds);
		ds=max(tree.get(pos[head[u]],pos[u]),ds);
		v=pre[head[v]];
		u=pre[head[u]];
	}
	if(pos[u]<=pos[v]) ds=max(tree.get(pos[u]+1,pos[v]),ds);
	else ds=max(ds,tree.get(pos[v]+1,pos[u]));
	return ds;
}
void build(int u,int dad){
    for(int i:ke[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        if(v!=dad){
            tree.upd(pos[v],e[i].l);
            build(v,u);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].l;
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++) t.ms(i);
    for(int i=1;i<=m;i++){
        if(!t.lt(e[i].u,e[i].v)){
            ke[e[i].u].push_back(i);
            ke[e[i].v].push_back(i);
            t.noi(e[i].u,e[i].v);
        }
    }
    dfs(1);
    hld(1,1);
    build(1,0);
    cin>>q;
    while(q--){
        int u,v;cin>>u>>v;
        cout<<calc(u,v)<<"\n";
    }
}
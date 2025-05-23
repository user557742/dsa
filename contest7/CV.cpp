#include<iostream>
#include <map>
#include <vector>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define X first 
#define Y second 
typedef long long ll;
const int maxn = 150000;
struct dsu{
    int pre[maxn];
    int sz[maxn];
    void ms(int u){
        pre[u]=u;
        sz[u]=1;
    }
    int find(int u){
        if(u==pre[u]) return u;
        return pre[u]=find(pre[u]);
    }
    void kh(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(sz[u]<sz[v])swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
}tt;
ll c2n(int n){
    return 1ll*(n-1)*n/2;
}
int n,m;
vector<int> adj[maxn];
map<pair<int,int>,int> canh;
struct E{
    int u,v,l;
}e[maxn];
bool chon[maxn];
vector<E> kodcchon;
int depth[maxn],st[maxn],id=0;
pair<int,int> rmq[25][2*maxn];
bool vis[maxn];
void dfs(int u,int dad){
    vis[u]=1;
	st[u]=id;
	rmq[0][id++]={depth[u],u};
	for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].v;
        if(v!=dad) if(!vis[v]){
            depth[v]=depth[u]+1;
            dfs(v,u);
            rmq[0][id++]={depth[u],u};
        }
	}
}
void prepare(){
	int k=__lg(id);
	rei(i,1,k){
		for(int j=0;j+(1<<i)-1<=id;j++) rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
	}
}
int get_lca(int u,int v){
	int l=st[u],r=st[v];
	if(l>r) swap(l,r);
	int i=__lg(r-l+1);
	return min(rmq[i][l],rmq[i][r-(1<<i)+1]).second;
}
ll gt[maxn];
void calc(int u,int dad){
    //cout<<"calc ok"<<"\n";
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        int l=e[i].l;
        if(v!=dad){
            gt[v]=gt[u]*l;
            //cout<<"#"<<u<<" "<<v<<" "<<gt[u]<<" "<<gt[v]<<" "<<l<<"\n";
            calc(v,u);
        }
    }
}
int main(){
    if(fopen("CV.INP","r")){
        freopen("CV.INP","r",stdin);
        freopen("CV.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rei(i,1,m){
        int u,v;cin>>u>>v;
        if(u>v) swap(u,v);
        canh[mp(u,v)]+=1;
    }
    rei(i,1,n) tt.ms(i);
    int iiiddd=1;
    for(auto x:canh){
        e[iiiddd].u=x.X.X;
        e[iiiddd].v=x.X.Y;
        e[iiiddd].l=x.Y;
        iiiddd++;
    }
    int m=canh.size();
    rei(i,1,m){
        int u=tt.find(e[i].u);
        int v=tt.find(e[i].v);
        if(u!=v) {
            tt.kh(e[i].u,e[i].v);
            chon[i]=1;
        }
    }
    //cout<<"!\n";
    rei(i,1,m){
        if(chon[i]){
            adj[e[i].u].push_back(i);
            adj[e[i].v].push_back(i);
        }
        else kodcchon.push_back(e[i]);
    }
    rei(i,1,n) if(!vis[i]){
        //cout<<"ok"<<"\n";
        id=0;
        dfs(i,0);
        gt[i]=1;
        calc(i,0);
        prepare();
    }
    //rei(i,1,n) cout<<gt[i]<<" ";
    ll ds=0;
    rei(i,1,m){
        ds+=c2n(e[i].l);
    }
    for(E x:kodcchon){
        int w=get_lca(x.u,x.v);
        ds+=(gt[x.u]/gt[w])*(gt[x.v]/gt[w])*x.l;
    }
    cout<<ds;
}

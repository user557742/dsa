#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
const ll oo = 1e18;
const int maxn = 5001;
const int maxm = 30001;
struct E{
    int u,v,c,f;
    E(int _u=0,int _v=0,int _c=0,int _f=0) : u(_u) , v(_v),c(_c),f(_f) { }
} e[4*maxm];
vector<int> adj[maxn];
int n,m,s,t;
int ptr[maxn];
ll d[maxn],id=0;
int cl[maxn];
bool check(){
    for(int i=1;i<=n;i++) d[i]=oo;
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i:adj[u]) {
            int v=(e[i].u==u )? e[i].v:e[i].u;
            if(d[v]==oo&&e[i].c>e[i].f){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]!=oo;
}
ll calc(int u,ll ds){
    if(u==t) return ds;
    if(cl[u]==id) return 0;
    for(int &x=ptr[u];x<(int)adj[u].size();x++){
        int i=adj[u][x];
        int v=(e[i].u==u)? e[i].v : e[i].u;
        if(cl[v]!=id&&e[i].c>e[i].f&&d[v]==d[u]+1){
            int delta=calc(v,min(ds,1ll*e[i].c-1ll*e[i].f));
            if(delta){
                e[i].f+=delta;
                e[i^1].f-=delta;
                return delta;
            }
        }
    }
    return 0;
}
ll maxflow(){
    ll mf=0;
    while(check()){
        memset(ptr,0,sizeof(ptr));
        while(ll delta=(id++,calc(s,oo))){
            mf+=delta;
        }
    }
    return mf;
}
int cnt=0;
void add(int u,int v,int l){
    e[cnt]=E(u,v,l,0);
    adj[u].push_back(cnt++);
    e[cnt]=E(v,u,0,0);
    adj[v].push_back(cnt++);
}
int main(){
    cin>>n>>m;
    for(int x=1;x<=m;x++){
        int u,v,c;cin>>u>>v>>c;
        add(u,v,c);
        add(v,u,c); 
    }
    s=1,t=n;
    cout<<maxflow();
}
#include <bits/stdc++.h>
using namespace std;
const int maxn =501;
const int maxm =1001;
const int inf = 1e9;
struct E{
    int u,v,c,f;
    E(int _u=0,int _v=0,int _c=0,int _f=0) : u(_u),v(_v),c(_c),f(_f) {}
};
vector<E> e;
vector<int> adj[maxn];
int d[maxn];
int n,m;
void adde(int u,int v,int c,int f){
    int i=e.size();
    e.push_back(E(u,v,c,f));
    e.push_back(E(v,u,0,0));
    adj[u].push_back(i);
    adj[v].push_back(i^1);
}
bool check(int s,int t){
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i:adj[u]){
            int v=e[i].v;
            if(d[v]>d[u]+1&&e[i].c>e[i].f){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return d[t]<inf;
}
int cl[maxn],id=0;
int fp(int u,int val,int t){
    if(u==t) return val;
    if(cl[u]==id) return 0;
    cl[u]=id;
    for(int i:adj[u]){
        int v=e[i].v;
        if(cl[v]!=id&&d[v]==d[u]+1&&e[i].c>e[i].f){
            if(int delta=fp(v,min(val,e[i].c-e[i].f),t)){
                e[i].f+=delta;
                e[i^1].f-=delta;
                return delta;
            }
        }
    }
    return 0;
}
int mf(int s,int t){
    int mf=0;
    while(check(s,t)){
        while(int delta=(id++,fp(s,inf,t))) mf+=delta;
    }
    return mf;
}
bool vis[maxn];
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i:adj[u]){
            int v=e[i].v;
            if(!vis[v]&&e[i].c>e[i].f){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        adde(u,v,1,0);
        adde(v,u,1,0);
    }
    cout<<mf(1,n)<< "\n";
    bfs(1);
    for(E x:e){
        if(x.f==1&&x.c==1&&vis[x.u]&&!vis[x.v]) cout<<x.u<< " "<<x.v<< "\n";
    }
    return 0;
}


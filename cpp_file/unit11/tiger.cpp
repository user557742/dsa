#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+1;
const int inf = 1e9;
#define rei(i,a,b) for(int i=a;i<=b;i++)
int n;
struct E{
    int u,v,c,f;
    E(int _u=0,int _v=0,int _c=0,int _f=0) : u(_u),v(_v),c(_c),f(_f) {}
};
struct dothi{
    vector<E> e;
    vector<int> adj[maxn];
    void adde(int u,int v,int c,int f){
        int i=e.size();
        adj[u].push_back(i);
        adj[v].push_back(i^1);
        e.push_back(E(u,v,c,f));
        e.push_back(E(v,u,0,0));
    }
    int d[maxn];
    bool check(int s,int t){
        rei(i,1,n) d[i]=inf;
        d[s]=0;d[t]=inf;
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
    int MF(int s,int t){
        int mf=0;
        while(check(s,t)){
            while(int delta=(id++,fp(s,inf,t))) mf+=delta;
        }
        return mf;
    }
    bool vis[maxn];
    int pre[maxn];
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
}goc,ns;
int main(){
    if(fopen("inp","r")){
        freopen("inp","r",stdin);
        freopen("out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    int u,v;
    while(cin>>u>>v){
        goc.adde(u,v,1,0);
        goc.adde(v,u,1,0);
    }
    int sobay=goc.MF(1,n);
    goc.bfs(1);
    for(int i=0;i<(int)goc.e.size();i++){
        E x=goc.e[i];
        if(x.c==1&&x.f==1&&goc.vis[x.u]&&!goc.vis[x.v]) ns.adde(x.u,n+1,1,0);
        else if(i%2==0&&goc.vis[x.u]&&goc.vis[x.v]){
            ns.adde(x.u,x.v,1,0);
            ns.adde(x.v,x.u,1,0);
        }
    }
    int sobia=ns.MF(1,n+1);
    cout<<sobay<< " "<<sobia;
    return 0;
}

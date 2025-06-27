#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
const int maxm = 100001;
const int oo=1e9;
struct E{
    int u,v,c,f;
    E(int _u=0,int _v=0,int _c=0,int _f=0) : u(_u),v(_v),c(_c),f(_f) {}
};
struct dinic{
    int n,m;    
    vector<E> e;
    vector<vector<int>> adj;
    int s,t;
    vector<int> d;
    int id=0;
    vector<int> cl;
    vector<int> ptr;
    void init(int _n=0,int _m=0,int _s=0,int _t=0){
        n=_n;m=_m;
        e.resize(2*m+2);
        adj.resize(n+1);
        d.resize(n+1);
        cl.resize(n+1);
        ptr.resize(n+1);
        for(int i=1;i<=n;i++) cl[i]=0;
        s=_s;
        t=_t;
    }
    bool check(){
        for(int i=1;i<=n;i++) d[i]=oo;
        d[s]=0;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i:adj[u]){
                int v=e[i].v;
                if(d[v]==oo&&e[i].c>e[i].f){
                    d[v]=d[u]+1;
                    q.push(v);
                }
            }
        }
        return d[t]!=oo;
    }
    int calc(int u,int ds){
        if(u==t) return ds;
        if(cl[u]==id) return 0;
        cl[u]=id;
        for(int &x=ptr[u];x<(int)adj[u].size();x++){
            int i=adj[u][x];
            int v=e[i].v;
            if(cl[v]!=id&&e[i].c>e[i].f&&d[v]==d[u]+1){
                int delta=calc(v,min(ds,e[i].c-e[i].f));
                if(delta){
                    e[i].f+=delta;
                    e[2*m+1-i].f-=delta;
                    return delta;
                }
            }
        }
        return 0;
    }
    int maxflow(){
        int mf=0;
        while(check()){
            fill(ptr.begin(),ptr.end(),0);
            while(int delta=(id++,calc(s,oo))){
                mf+=delta;
            }
        }
        return mf;
    }
}D;
int a[maxn],b[maxn],c[maxn];
int n,m;
int main(){
    cin>>n>>m;
    D.init(n,m,1,n);
    for(int i=1;i<=m;i++){
        cin>>D.e[i].u>>D.e[i].v>>D.e[i].c;
        D.e[2*m+1-i]=E(D.e[i].v,D.e[i].u);
        D.adj[D.e[i].u].push_back(i);
        D.adj[D.e[2*m+1-i].u].push_back(2*m+1-i);
    }
    cout<<D.maxflow();
}
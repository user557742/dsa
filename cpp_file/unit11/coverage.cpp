#include<bits/stdc++.h>
using namespace std;
const int maxn = 401;
const int inf= 1e9;
vector<int> adj[maxn];
int n;
int a[maxn],b[maxn];
int c[maxn][maxn];
struct E{
    int u,v,c,f;
    E(int _u=0,int _v=0,int _c=0,int _f=0) : u(_u),v(_v),c(_c),f(_f) {}
};
vector<E> e;
void adde(int u,int v,int c,int f){
    int i=e.size();
    e.push_back(E(u,v,c,f));
    e.push_back(E(v,u,0,0));
    adj[u].push_back(i);
    adj[v].push_back(i^1);
}
int d[maxn];
bool check(int s,int t){
    for(int i=1;i<=n;i++) d[i]=inf;
    d[s]=0;d[t]=inf;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
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
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>c[i][j];
    for(int i=1;i<=n;i++) adde(n+1,i,a[i],0);
    for(int i=1;i<=n;i++) adde(i,n+2,b[i],0);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) adde(i,j,c[i][j],0);
    cout<<MF(n+1,n+2);
    return 0;
}

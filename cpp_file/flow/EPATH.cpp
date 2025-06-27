#include <bits/stdc++.h>
using namespace std;
const int maxn = 1001;
const int maxm = 50001;
const int  oo =1e9;
int d[maxn],cl[maxn];
vector<int> adj[maxn];
int id=0,cnt=0,ptr[maxn];
typedef long long ll;
int pre[maxn];
int n,m;
struct E{
    int u,v,c,f;
    E(int _u=0,int _v=0,int _c=0,int _f=0) : u(_u),v(_v),c(_c),f(_f) {}
} e[2*maxm];
void add(int u,int v,int c){
    e[cnt]=E(u,v,c,0);
    adj[u].push_back(cnt++);
    e[cnt]=E(v,u,0,0);
    adj[v].push_back(cnt++);
}
int s,t;
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
vector<vector<int>> ds;
int calc(int u,int ds){
    if(u==t) return ds;
    if(cl[u]==id) return 0;
    cl[u]=id;
    for(int &x=ptr[u];x<(int)adj[u].size();x++){
        int i=adj[u][x];
        int v=e[i].v;
        if(cl[v]!=id&&e[i].c>e[i].f&&d[v]==d[u]+1){
            pre[v]=u;
            int delta=calc(v,min(ds,e[i].c-e[i].f));
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
        while(int delta=(id++,calc(s,oo))){
            vector<int> ans;
            int u=t;
            ans.push_back(u);
            while(u!=s){
                u=pre[u];
                ans.push_back(u);
            }
            mf+=delta;
            reverse(ans.begin(),ans.end());
            ds.push_back(ans);
        }
    }
    return mf;
}
int main(){
    cin>>n>>m;
    cin>>s>>t;
    while(m--){
        int u,v;cin>>u>>v;
        add(u,v,1);
    }
    cout<<maxflow()<<"\n";
    for(vector<int> ans:ds){
        cout<<ans.size()<<" ";
        for(int x:ans) cout<<x<<" ";
        cout<<"\n";
    }
}
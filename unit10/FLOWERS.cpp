#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+1;
vector<int> adj[maxn];
int cl[maxn];
vector<int> tplt[maxn];
int nen[maxn];
int stplt=0;
int low[maxn],num[maxn],id=0;
stack<int> s;
void tarjan(int u){
    cl[u]=1;
    num[u]=low[u]=++id;
    s.push(u);
    for(int v:adj[u])
    {
        if(cl[v]==0)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(cl[v]==1)
        low[u]=min(low[u],num[v]);
    }
    if(num[u]==low[u])
    {
        ++stplt;
        int v;
        do{
            v=s.top();
            s.pop();
            nen[v]=stplt;
            tplt[stplt].push_back(v);
            cl[v]=2;
        }while(v!=u);
    }
}
int n,u,v;
int out[maxn];
vector<pair<int,int>> e;
int main(){
    if(fopen("in.inp","r")){
        freopen("in.inp","r",stdin);
        freopen("out.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(cin>>u>>v){
        adj[u].push_back(v);
        e.push_back({u,v});
    }
    for(int i=1;i<=n;i++) if(cl[i]==0) tarjan(i);
    for(pair<int,int> p:e){
        int u=p.first;
        int v=p.second;
        if(nen[u]!=nen[v]) out[nen[u]]++;
    }
    int ds=1e9;
    int v=0;
    for(int i=1;i<=stplt;i++) if(out[i]==0){
        if(ds>(int)tplt[i].size()){
            ds=tplt[i].size();
            v=i;
        }
    }
    cout<<ds<<"\n";
    sort(tplt[v].begin(),tplt[v].end());
    for(int x:tplt[v]) cout<<x<<" ";
}
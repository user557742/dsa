#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5+1;
#define rei(i,a,b) for(int i=(a);i<=(b);i++)
struct DSU{
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
    void dsu(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
} d;
struct E{
    int u,v,l;
};
bool cmp(E a,E b){
    return a.l<b.l;
}
E e[maxn];
int n,m;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rei(i,1,m) cin>>e[i].u>>e[i].v>>e[i].l;
    sort(e+1,e+m+1,cmp);
    rei(i,1,n) d.ms(i);
    long long ds=0;
    rei(i,1,m){
        if(d.find(e[i].u)!=d.find(e[i].v)){
            ds+=e[i].l;
            d.dsu(e[i].u,e[i].v);
        }
    }
    cout<<ds;
}
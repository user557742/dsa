// n hon dao co n-1 tuyen pha de di chuyen 
// có thể thay thế k tuyến phà bằng k câu cầu
// di trên cầu sẽ tốn ít thời gian hơn 
// Vc , Vp là vận tốc đi trên cầu và trên phà 
// tìm cách thay thế sao cho tổng thời gian đi trên mọi cặp đỉnh là nhỏ nhất
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int maxn=1e5+1;
int sz[maxn];
vector<int> adj[maxn];
struct E{
    int u,v;
    long long l;
    E(int _u=0,int _v=0,long long _l=0) : u(_u),v(_v),l(_l) {}
} e[maxn];
ll k,n,vc,vp;
void dfs(int u,int dad){
    sz[u]=1;
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;    
        if(v!=dad){
            dfs(v,u);
            sz[u]+=sz[v];
        }
    } 
}
pair<long long,int> gt[maxn];

int main(){
    cin>>n>>k>>vp>>vc;
    rei(i,1,n-1) cin>>e[i].u>>e[i].v>>e[i].l;
    rei(i,1,n-1){
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    dfs(1,0);
    rei(i,1,n-1){
        ll s=min(sz[e[i].u],sz[e[i].v]);
        gt[i]={1ll*e[i].l*s*(n-s),i};
    }sort(gt+1,gt+n);
    if(vc>vp){   
        for(int i=n-1;i>=n-k;i--) cout<<gt[i].second<<"\n"; 
    }
    else{
        for(int i=1;i<=k;i++) cout<<gt[i].second<<"\n";
    }
    
    
}

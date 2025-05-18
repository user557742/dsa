// dp[u] cay con co tong trong so lon nhat 
// xet v1,v2,...,vk la cac con cua u ma ke voi u
// dp[v]<0 thi khong chon
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 2e5+1;
#define rei(i,a,b) for(int i=a;i<=b;i++)
struct E{
    int u,v,l;
    E(int _u=0,int _v=0,int _l=0) : u(_u) , v(_v),l(_l) {}
};int n;
E e[maxn];
int dp[maxn];
vector<int> adj[maxn];
void dfs(int u,int dad){
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        int l=e[i].l;
        if(v!=dad){
            dfs(v,u);
            if(dp[v]+l>=0) dp[u]+=dp[v]+l; 
        }
    }
}
int main(){
    cin>>n;
    rei(i,1,n-1) cin>>e[i].u>>e[i].v>>e[i].l;
    rei(i,1,n-1){
        adj[e[i].u].push_back(i);
        adj[e[i].v].push_back(i);
    }
    dfs(1,0);
    int ds=0;
    rei(i,1,n) ds=max(ds,dp[i]);
    cout<<ds;
}
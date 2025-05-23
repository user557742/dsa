// nếu có 2 tplt trở lên thì không thể có cây khung 
// xây dựng hàm f(x) kiểm tra xem với x là độ chênh lớn nhất giữa cây khung thì có tồn tại cây khung không
#include <iostream>
#include <vector>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 10000;
int n;
struct E{
    u,v,l;
}e[maxn];
vector<int> adj[maxn];int m;
bool vis[maxn];int sl=0;
void dfs(int u){
    vis[u]=1;
    for(int v:adj[u]) if(!vis[v]) dfs(v);
}
struct DSU{
    int pre[maxn],sz[maxn];
    void init(int _n){
        rei(i,1,_n) {
            pre[i]=0;
            sz[i]=0;
        }
    }
    void ms(int u){
        pre[u]=u;
        sz[u]=1;
    }
    int find(int u){
        if(pre[u]==u) return u;
        return pre[u]=find(pre[u]);
    }
    void kh(int u,int v){
        u=find(u);
        v=find(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
};
bool cmp(E u,E v){
    return u.l<v.l;
}
bool f(int x){
    rei(i,1,m){
        
    }
}
int main(){
    cin>>n>>m;
    rei(i,1,m) {
        cin>>e[i].u>>e[i].v>>e[i].l;
        adj[e[i].u].push_back(e[i].v);
        adj[e[i].v].push_back(e[i].u);
    }
    sort(e+1,e+m+1);
    rei(i,1,n) if(!vis[i]){
        sl++;
        dfs(i);
    }
    if(sl>1){
        cout<<"NO";
        return 0;
    }

}   
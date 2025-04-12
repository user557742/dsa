// tư tưởng : trong cây khung mỗi khi thêm một cạnh thì ta được một số chu trình mới
// do đó khi thêm một cạnh cạnh vào cây khung ta có thể tạo ra một số chu trình
// khi cây khung lớn nhất được xây đựng thì các cạch có thể thêm vào để thành chu trình đều là một trong những cạch nhỏ nhất và luôn thuộc một chu trình nào đó 
// vì không phải đa đồ thị nên giữa 2 đỉnh chỉ có duy nhất 1 đường đi đo đó các cạch còn lại không thuộc cây khung lớn nhất đều là đáp án
#include <bits/stdc++.h>
using namespace std;
const int N= 1e6+1;
int n,m;
struct DSU{
    vector<int> sz;
    vector<int> pre;
    void init(int n){
        pre.resize(n+1,0);
        sz.resize(n+1,0);
    }
    void make_set(int v){
        sz[v]=1;
        pre[v]=v;
    }
    int tim(int u){
        return (u==pre[u]) ? u : pre[u]=tim(pre[u]);
    }
    void join(int u,int v){
        u=tim(u);
        v=tim(v);
        if(u!=v){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];
            pre[v]=u;
        }
    }
    bool cungtplt(int u,int v){
        return tim(u)==tim(v);
    }
} k;
struct cach{
    int u,v,l;
} e[N];
bool cmp(cach a,cach b){
    if(a.l==b.l) return make_pair(a.u,a.v)>make_pair(b.u,b.v);
    return a.l>b.l;
}
bool ok[N];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].l;
    sort(e+1,e+m+1,cmp);
    /*cout<<"####################\n";
    for(int i=1;i<=m;i++) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].l<<"\n";*/
    k.init(n);
    for(int i=1;i<=n;i++) k.make_set(i);
    for(int i=1;i<=m;i++){
        if(k.cungtplt(e[i].u,e[i].v)) continue;
        k.join(e[i].u,e[i].v);
        ok[i]=1;
    }
    /*cout<<"####################\n";
    for(int i=1;i<=m;i++) if(!ok[i]) cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].l<<"\n";*/
    int ds=0;
    for(int i=1;i<=m;i++)if(!ok[i]){
        ds+=e[i].l;
    }
    cout<<ds;
    return 0;
}


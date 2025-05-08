// Đề bài : cho một cây n đỉnh hỏi nếu chi phí ngắn nhất để đi hết n con đường bằng 2 xe bắt đầu từ một đỉnh 
// tư tưởng tìm độ dài đường đi dài nhất và nhì ít phần chung nhất
// đánh dấu các phần đó ds = tổng các cạnh không bị đánh dấu và  
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
struct canh{
    int u,v,l;
    canh(int _u=0,int _v=0,int _l=0) : u(_u),v(_v),l(_l) {}
};
canh e[maxn];
vector<int>adj[maxn];
int n;
int st;
int d[maxn];
pair<int,int> pre[maxn];
int nho[maxn];
void dfs(int u,int dad){
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v : e[i].u;
        int l=e[i].l;
        if(v!=dad){
            pre[v]={u,i};
            d[v]=d[u]+l;
            dfs(v,u);
        }
    }
}
pair<int,int> rmq[20][maxn];
int depth[maxn];
int id=0;
int bd[maxn];
void dfsd(int u,int dad){
    bd[u]=id;
    rmq[0][id++]={depth[u],u};
    for(int i:adj[u]){
        int v=(e[i].u==u) ? e[i].v:e[i].u;
        if(v!=dad){
            depth[v]=depth[u]+1;
            dfsd(v,u);
            rmq[0][id++]={depth[v],v};
        }
    }
}
void prepare(){
    int k=__lg(id);
    rei(i,1,k){
        for(int j=0;j+(1<<i)-1<=id;j++){
            rmq[i][j]=min(rmq[i-1][j],rmq[i-1][j+(1<<(i-1))]);
        }
    }
}
int lca(int u,int v){
    int l=bd[u];
    int r=bd[v];
    if(l>r) swap(l,r);
    int i=__lg(r-l+1);
    return min(rmq[i][l],rmq[i][r-(1<<i)+1]).Y;
}
void inp(){
    cin>>n>>st;
    rei(i,1,n-1) cin>>e[i].u>>e[i].v>>e[i].l;
    rei(i,1,n-1){
        adj[e[i].u].pb(i);
        adj[e[i].v].pb(i);
    }
}
void solve(){
    dfs(st,0);
    dfsd(st,0);
    prepare();
    ll t=0;
    rei(i,1,n-1) t+=e[i].l;
    ll ds=1e18;
    rei(i,1,n) if(i!=st){
        rei(j,1,n) if(j!=st) if(i!=j){
            ds=min(ds,2*t-d[i]-d[j]+2*d[lca(i,j)]);
        }
    }
    cout<<ds;
}
int main(){
    //clock_t ____st=clock();
    /*ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    inp();
    solve();

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
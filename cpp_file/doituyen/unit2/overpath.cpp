#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


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
int n;
int a[maxn];
int cnt[maxn];
vector<int> adj[maxn];
int depth[maxn];
int pre[maxn];

void dfs(int u,int dad){
    for(int v:adj[u]) if(v!=dad){
        pre[v]=u;
        depth[v]=depth[u]+1;
        dfs(v,u);
    }
}
int sub1(int u,int v){
    int x=u;
    int y=v;
    rei(i,1,n) cnt[i]=0;
   
    while(depth[u]>depth[v]){
        cnt[a[u]]++;
        u=pre[u];
        
    }
    while(depth[v]>depth[u]){
        cnt[a[v]]++;
        v=pre[v];
        
    }
    while(u!=v){
        
        cnt[a[u]]++;
        cnt[a[v]]++;
        u=pre[u];
        v=pre[v];
    }
    cnt[a[u]]++;
    int ds=0;
    int l=0;
    rei(i,1,n) if(l<cnt[i]){
        l=cnt[i];
        ds=i;
    }
    int dai = depth[x]-2*depth[u]+1+depth[y];
    //cout<<dai<<" "<<l<<"\n";
    if(2*l>dai) return ds;
    return -1;
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n-1){
        int u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    /*int m;cin>>m;
    while(m--){
        int u,v;cin>>u>>v;
        cout<<solve(u,v)<<"\n";
    }*/
    /*clock_t ____end=clock();
    
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
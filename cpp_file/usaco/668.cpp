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
ll x[maxn],y[maxn],p[maxn];
vector<int> adj[maxn];
bool vis[maxn];
int cnt=0;
void bfs(int st){
    rei(i,1,n) vis[i]=0;
    queue<int> q;
    q.push(st);
    vis[st]=1;
    cnt++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]) if(!vis[v]){
            vis[v]=1;cnt++;
            q.push(v);
        }
    }
}
int main(){
    //clock_t ____st=clock();
    if(fopen("moocast.in","r")){
        freopen("moocast.in","r",stdin);
        freopen("moocast.out","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>p[i];
    }
    rei(i,1,n) rei(j,1,n){
        if(((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))<=p[i]*p[i]){
            adj[i].pb(j);
        }
    }
    int ds=0;
    rei(i,1,n){
        cnt=0;
        bfs(i);
        ds=max(ds,cnt);
    }
    cout<<ds;
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
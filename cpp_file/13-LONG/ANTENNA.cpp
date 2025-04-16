#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
#define X first
#define Y second
#define rei(i,l,r) for (int i=l;i<=r;i++)
typedef pair<double,double> p2d;
p2d a[maxn];int n;
vector<int> adj[maxn];
bool oks(p2d u,p2d v,double r){
    return sqrt((u.X-v.X)*(u.X-v.X)+(u.Y-v.Y)*(u.Y-v.Y))<=2*r;
}
bool vis[maxn];
void bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st]=1;
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]) if(!vis[v]){
            q.push(v);
            vis[v]=1;
        } 
    }
}
bool f(double r){   
    for(int i=1;i<=n;i++){
        adj[i].clear();
        vis[i]=0;
    }
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) if(i!=j){
        if(oks(a[i],a[j],r)){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    int ds=0;
    for(int i=1;i<=n;i++) if(!vis[i]){
        ds++;
        if(ds>1) return 0;
        bfs(i);
    }
    return 1;
}
double bs(){
    double lo=0,hi=1;
    double ss=0.000000001;
    while(!f(hi)){
        lo=hi;
        hi*=2;
    }
    while(lo+ss<hi){
        double mid=(lo+hi)/2;
        if(f(mid)) hi=mid;
        else lo=mid;
    }
    return hi;
}
int main(){
    if(fopen("ANTENNA.INP","r")){
        freopen("ATENNA.INP","r",stdin);
        freopen("ATENNA.OUT","w",stdout);
    }
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i].X>>a[i].Y;
    cout<<fixed;
    cout<<setprecision(7);
    cout<<bs();
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
/*7
2 3
3 4
4 5
0 1
3 1
4 2
1 5*/
#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define X first
#define Y second
#define mp make_pair
#define pb push_back
const int maxn = 1001;
const int maxm = 1001;
const int oo = 1e9;
typedef pair<int,int> ii;

vector<int> adj[maxn][maxn];
int d[maxn][maxn];
int cl[maxn][maxn];
int n,m;
int id=0,cnt=0;
ii s,t;
struct E{
    ii u,v;int c,f;
    E(ii _u=mp(0,0),ii _v=mp(0,0),int _c=0,int _f=0) : u(_u),v(_v),c(_c),f(_f) {}
} e[1000001];
void add(ii u,ii v,int c){
    e[cnt]=E(u,v,c,0);
    adj[u.X][u.Y].pb(cnt++);
    e[cnt]=E(v,u,0,0);
    adj[v.X][v.Y].pb(cnt++);
}

bool check(){
    rei(i,0,n+1) rei(j,0,m+1) d[i][j]=oo;
    queue<ii> q;
    d[s.X][s.Y]=0;
    q.push(s);
    while(!q.empty()){
        ii u=q.front();
        q.pop();
        for(int i:adj[u.X][u.Y]) {
            ii v=e[i].v;
            if(d[v.X][v.Y]==oo&&e[i].c>e[i].f){
                d[v.X][v.Y]=d[u.X][u.Y]+1;
                q.push(v);
            }
        }
    }
    return d[t.X][t.Y]!=oo;
}
int ptr[maxn][maxn];
int calc(ii u,int ds){
    if(u==t) return ds;
    if(cl[u.X][u.Y]==id) return 0;
    cl[u.X][u.Y]=id;
    for(int &x=ptr[u.X][u.Y];x<(int)adj[u.X][u.Y].size();x++){
        int i=adj[u.X][u.Y][x];
        ii v=e[i].v;
        if(cl[v.X][v.Y]!=id&&e[i].c>e[i].f&&d[v.X][v.Y]==d[u.X][u.Y]+1){
            int delta=calc(v,min(ds,e[i].c-e[i].f));
            if(delta){
                e[i].f+=delta;
                e[i^1].f-=delta;
                return delta;
            }
        }
    }
    return 0;
}
int maxflow(){
    int mf=0;
    while(check()){
        memset(ptr,0,sizeof(ptr));
        while(int delta=(++id,calc(s,oo))){
            mf+=delta;
        }
    }
    return mf;
}
int main(){
    cin>>n>>m;
    rei(j,1,m-1){
        rei(i,1,n){
            int sl;cin>>sl;
            while(sl--){
                int x;cin>>x;
                add(mp(i,j),mp(x,j+1),1);
            }
        }
    }
    s={n+1,m};
    t={n,m+1};
    rei(i,1,n){
        add(s,mp(i,1),1);
        add(mp(i,m),t,1);
    }
    cout<<maxflow();
}
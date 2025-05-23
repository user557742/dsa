#include <iostream>
#include <set>
#include <cstdio>
#define mp make_pair
#define rei(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
typedef long long ll;
const int maxn=2001;
const ll INF=1e18;
int n,m,l;
int a[maxn][maxn];
ll d[maxn][maxn];
pair<int,int> p[maxn*100];
int _x[4]={0,1,0,-1};
int _y[4]={1,0,-1,0};
void dijsktra(int sx,int sy){
    rei(i,1,n) rei(j,1,m) d[i][j]=INF;
    d[sx][sy]=0;
    set<pair<ll,pair<int,int>>> q;
    q.insert(mp(0,mp(sx,sy)));
    while(!q.empty()){
        auto it=q.begin();
        ll du=it->first;
        int x=it->second.first,y=it->second.second;
        q.erase(it);
        if(du!=d[x][y]) continue;
        rei(k,0,3){
            int nx=x+_x[k],ny=y+_y[k];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(_y[k]==0&&y!=1&&y!=m) continue;
            ll nd=du+a[nx][ny];
            if(nd<d[nx][ny]){
                d[nx][ny]=nd;
                q.insert(mp(nd,mp(nx,ny)));
            }
        }
    }
}
ll s[maxn][maxn];
ll p1[maxn],pm[maxn];
ll calc(int x1,int y1,int x2,int y2){
    // th1 : 1----(x1,y1) (x2,y2)----m
    ll ds=1e18;
    ll l=s[x1][y1];
    ll r=s[x2][m]-s[x2][y2-1];
    rei(i,1,n){
        ll nds=l+r+s[i][m];
        if(i<x1){
            if(i<x2){
                nds+=p1[x1]-p[i-1]+pm[x2]-pm[i-1];
            }
            else if(i>x2){
                nds+=p1[x1]-p[i-1]+pm[i]-pm[x2-1];
            }
            else if(i==x2){
                if(x1>x2){
                    nds+=p1
                }
            }
        }
        else if(i>x1)
    }
}
int main(){
    if(fopen("PIZZA.INP","r")){
        freopen("PIZZA.INP","r",stdin);
        freopen("PIZZA.OUT","w",stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    rei(i,1,n) rei(j,1,m) cin>>a[i][j];
    rei(i,1,n){
        rei(j,1,m) s[i][j]+=s[i][j-1]+a[i][j];
        p1[i]+=a[i][1];
        pm[i]+=a[i][m];
    }

    cin>>l;
    rei(i,1,l) cin>>p[i].first>>p[i].second;
    ll ds=0;
    ds+=a[1][1];
    int cx=1,cy=1;
    dijsktra(cx,cy);
    rei(i,1,l){
        int tx=p[i].first,ty=p[i].second;
        ds+=d[tx][ty];
        cx=tx;cy=ty;
        if(i<l) dijsktra(cx,cy);
    }
    cout<<ds;
    return 0;
}

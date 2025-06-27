#include <iostream>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++) 
typedef long long ll;
const int maxn = 2001;
int n,m;
ll a[maxn][maxn];
int q;
pair<int,int> p[maxn];
ll g[maxn][maxn];
ll s1[maxn],sm[maxn];
ll dis(int x1,int y1,int x2,int y2){
    if(x1<x2){
        swap(x1,x2);
        swap(y1,y2);
    }
    ll ds=1e18;
    ll l1=g[x1][y1]-a[x1][1],r1=g[x1][m]-g[x1][y1-1]-a[x1][m];
    ll l2=g[x2][y2]-a[x2][1],r2=g[x2][m]-g[x2][y2-1]-a[x2][m];
    for(int i=1;i<=n;i++){
        if(i<x2){
            ds=min(ds,g[i][m]+s1[x1]-s1[i-1]+sm[x2]-sm[i-1]+l1+r2-a[i][m]-a[i][1]);
            ds=min(ds,g[i][m]-s1[i-1]-sm[i-1]+sm[x1]+s1[x2]+l2+r1-a[i][m]-a[i][1]);
        }
        if(i>x1){
            ds=min(ds,g[i][m]+s1[i]+sm[i]-s1[x1-1]-sm[x2-1]+l1+r2-a[i][m]-a[i][1]);
            ds=min(ds,g[i][m]+s1[i]+sm[i]-sm[x1-1]-s1[x2-1]+l2+r1-a[i][m]-a[i][1]);
        }
        if(x1==i||x2==i){
            if(x1!=x2){
                ds=min(ds,l1+l2+s1[x1]-s1[x2-1]);
                ds=min(ds,r1+r2+sm[x1]-sm[x2-1]);
            }
            else ds=min(ds,g[x1][max(y1,y2)]-g[x1][min(y1,y2)-1]);
        }
        if(x1<i&&i<x2){
            ds=min(ds,g[i][m]+sm[i]-sm[x2-1]+s1[x1]-s1[i-1]+r2+l1-a[i][m]-a[i][1]);
            ds=min(ds,g[i][m]+s1[i]-s1[x2-1]+sm[x1]-sm[i-1]+l2+r1-a[i][m]-a[i][1]);
        }
    }
    return ds;
}
int main(){
    cin>>n>>m;
    rei(i,1,n) rei(j,1,m) cin>>a[i][j];
    cin>>q;
    rei(i,1,q) cin>>p[i].first>>p[i].second;
    rei(i,1,n){
        s1[i]=s1[i-1]+a[i][1];
        sm[i]=sm[i-1]+a[i][m];
        rei(j,1,m) g[i][j]=g[i][j-1]+a[i][j];
    }
    long long ds=0;
    ds+=dis(1,1,p[1].first,p[1].second)-a[p[1].first][p[1].second];
    //cout<<dis(1,1,p[1].first,p[1].second)<<" ";
    rei(i,1,q-1){
        //cout<<dis(p[i].first,p[i].second,p[i+1].first,p[i+1].second)<<" ";
        ds+=dis(p[i].first,p[i].second,p[i+1].first,p[i+1].second)-a[p[i+1].first][p[i+1].second];
    }
    //cout<<"\n";
    cout<<ds+a[p[q].first][p[q].second];
}
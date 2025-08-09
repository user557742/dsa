#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn  = 5e2+1;
int n,m,d,lim;
int a[maxn][maxn];
struct o{
    int v,x,y;
    o(int _v=0,int _x=0,int _y=0) : v(_v),x(_x),y(_y) {}
} s[maxn*maxn];
bool cmp(o u,o v){
    if(u.v==v.v) return make_pair(u.x,u.y)<make_pair(v.x,v.y);
    return u.v<v.v;
}
int dp[maxn*maxn];
int main(){
    if(fopen("INCCELLS.INP","r")){
        freopen("INCCELLS.INP","r",stdin);
        freopen("INCCELLS.ANS","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>d;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            s[++lim]=o(a[i][j],i,j);
        }
    }
    sort(s+1,s+lim+1,cmp);
    rei(i,1,lim){
        dp[i]=1;
        rei(j,1,i-1){
            if(s[i].v>s[j].v&&abs(s[i].x-s[j].x)+abs(s[i].y-s[j].y)<=d) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ds=0;
    rei(i,1,lim) ds=max(ds,dp[i]);
    cout<<ds;
    return 0;
}

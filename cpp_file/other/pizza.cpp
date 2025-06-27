#include <bits/stdc++.h>
#define pii pair<int,int>
#define ii pii
#define fi first
#define sc second
#define ll long long
#define pll pair<ll,ll>
#define ill pair<int,ll>
#define lli pair<ll,int>
#define inf -1
#define INF inf
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define llinf (ll)1e18
#define LLINF llinf
#define maxn 2005
#define maxm
#define task "PIZZA"
using namespace std;

int r,c;
ll a[maxn][maxn], sum[maxn][maxn];
int m;

int g[maxn][2][3], dp[maxn][2][maxn][2];

int minmin(int a,int b){
    if(a==inf) return b;
    if(b==inf) return a;
    return (a<b) ? a:b;
}

void initsum(){
    for(int i=0;i<r;i++) {
        sum[i][0] = a[i][0];
        for(int j=1;j<c;j++) sum[i][j]=sum[i][j-1]+a[i][j];
    }
}

int getsum(int i,int l,int r){
    if(r==0) return 0;
    if(l==0) return sum[i][r-1];
    return sum[i][r-1]-sum[i][l-1];
}

void initg(){
    for(int i=0;i<r;i++){
        // [][0][] : dau hang
        // [][1][] : cuoi hang
        // [][][0] : len tren
        // [][][2] : xuong duoi
        // [][][1] : di sang dau ben kia cua hang

        if(i==0) g[i][0][0]=g[i][1][0]=inf;
        else{
            g[i][0][0]=a[i-1][0];
            g[i][1][0]=a[i-1][c-1];
        }

        if(i+1==r) g[i][0][2]=g[i][1][2]=inf;
        else{
            g[i][0][2]=a[i+1][0];
            g[i][1][2]=a[i+1][c-1];
        }

        g[i][0][1]=getsum(i,1,c);
        g[i][1][1]=getsum(i,0,c-1);
    }
}

void initdp(){
    memset(dp,inf,sizeof dp);

    for(int k=0;k<2;k++) for(int i=0;i<r;i++){
        dp[i][k][i][k]=0;

        ll L=0, R=0;
        for(int j=i;; j++){
            // di tu dau nay sang dau kia
            // bang cach di qua mot hang trung gian ben tren
            dp[i][k][i][1-k]=minmin(dp[i][k][i][1-k],L+R+g[j][k][1]);
            if(j+1==r) break;
            L+=g[j][k][2];
            R+=g[j+1][1-k][0];
        }

        L=R=0;
        for(int j=i;; j--){
            // di tu dau nay sang dau kia
            // bang cach di qua mot hang trung gian ben duoi
            dp[i][k][i][1-k]=minmin(dp[i][k][i][1-k],L+R+g[j][k][1]);
            if(j-1<0) break;
            L+=g[j][k][0];
            R+=g[j-1][1-k][2];
        }
    }

    for(int t=1;t<r;t++){
        for(int i=0;i<r-t;i++) for(int k=0;k<2;k++){
            /// di tu dau nay cua mot hang den dau cung phia cua hang ben duoi
            // chuyen trang thai 1: i+1 -> i bang cach di thang
            dp[i][k][i+t][k]=minmin(dp[i][k][i+t][k],dp[i+1][k][i+t][k]+g[i][k][2]);
            // chuyen trang thai 2: i+1 -> i bang cach di sang dau doi dien o i+1 roi len i va ve lai o can den
            dp[i][k][i+t][k]=minmin(dp[i][k][i+t][k],dp[i][k][i][1-k]+g[i][1-k][2]+dp[i+1][1-k][i+t][k]);
            /// tuong tu (dau nay cua 1 hang den dau doi dien cua hang ben duoi)
            dp[i][k][i+t][1-k]=minmin(dp[i][k][i+t][1-k],g[i][k][2]+dp[i+1][k][i+t][1-k]);
            dp[i][k][i+t][1-k]=minmin(dp[i][k][i+t][1-k],dp[i][k][i][1-k]+g[i][1-k][2]+dp[i+1][1-k][i+t][1-k]);
        }

        for(int i=t;i<r;i++) for(int k=0;k<2;k++){
            dp[i][k][i-t][k]=minmin(dp[i][k][i-t][k],dp[i-1][k][i-t][k]+g[i][k][0]);
            dp[i][k][i-t][k]=minmin(dp[i][k][i-t][k],dp[i][k][i][1-k]+g[i][1-k][0]+dp[i-1][1-k][i-t][k]);
            dp[i][k][i-t][1-k]=minmin(dp[i][k][i-t][1-k],g[i][k][0]+dp[i-1][k][i-t][1-k]);
            dp[i][k][i-t][1-k]=minmin(dp[i][k][i-t][1-k],dp[i][k][i][1-k]+g[i][1-k][0]+dp[i-1][1-k][i-t][1-k]);
        }
    }
}

int distance (int r1,int c1,int r2,int c2){
    int ds=inf;

    ds=minmin(ds, getsum(r1,0,c1) + dp[r1][0][r2][0] + getsum(r2,1,c2+1));
    ds=minmin(ds, getsum(r1,0,c1) + dp[r1][0][r2][1] + getsum(r2,c2,c-1));

    ds=minmin(ds, getsum(r1,c1+1,c) + dp[r1][1][r2][0] + getsum(r2,1,c2+1));
    ds=minmin(ds, getsum(r1,c1+1,c) + dp[r1][1][r2][1] + getsum(r2,c2,c-1));

    if(r1==r2){
        if(c1<c2) ds=minmin(ds, getsum(r1,c1+1,c2+1));
        else ds=minmin(ds, getsum(r1,c2,c1));
    }

    return ds;
}

int main(){
    if (fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c;
    for(int i=0;i<r;i++) for(int j=0;j<c;j++) cin>>a[i][j];
    initsum();
    initg();
    initdp();
    cin>>m;
    ll res=a[0][0];

    int lastr=0,lastc=0;
    while(m--){
        int u,v; cin>>u>>v;
        res+=distance(lastr,lastc,u-1,v-1);
        lastr=u-1, lastc=v-1;
    }
    cout<<res<<endl;

    return 0;
}
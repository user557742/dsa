#include <bits/stdc++.h>
using namespace std;
const int N=15;
string a[N+1];
int n,m;
int c[1001][1001];
int f(string u,string v){
    int ds=0;
    for(int i=0;i<n;i++){
        if(u[i]!=v[i]) ds+=1;
    }
    return ds;
}
int dp[1<<N][N+1];
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            c[i][j]=f(a[i],a[j]);
        }
    }
    string base="";
    for(int i=1;i<=n;i++) base+="0";
    for(int x=0;x<(1<<m);x++) for(int i=1;i<=m;i++) dp[x][i]=1e9;
    for(int i=1;i<=m;i++) dp[1<<(i-1)][i]=f(base,a[i]);
    for(int x=0;x<(1<<m);x++){
        for(int i=1;i<=m;i++) if(getbit(i,x)){
            for(int j=1;j<=m;j++) if(!getbit(j,x)){
                int y=x|(1<<(j-1));
                dp[y][j]=min(dp[y][j],dp[x][i]+c[i][j]);
            }
        }
    }
    int ds=1e9;
    for(int i=1;i<=m;i++) ds=min(ds,dp[(1<<m)-1][i]);
    cout<<ds;
}
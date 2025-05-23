#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int INF = 1e9;
const int maxn = 1001;
int getp2(int x) {
    int cnt = 0;
    while (x%2==0) {
        x /= 2;
        cnt++;
    }
    return cnt;
}
int getp5(int x) {
    int cnt = 0;
    while (x%5==0) {
        x /= 5;
        cnt++;
    }
    return cnt;
}
int n;
int a2[maxn][maxn], a5[maxn][maxn];
int dp2[maxn][maxn], dp5[maxn][maxn];
int main() {
    if (fopen("LEASTZERO.INP","r")) {
        freopen("LEASTZERO.INP","r",stdin);
        freopen("LEASTZERO.OUT","w",stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    int zi=-1, zj=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            if(x==0){
                zi=i;zj=j;
                a2[i][j]=a5[i][j]=INF;
            } else {
                a2[i][j]=getp2(x);
                a5[i][j]=getp5(x);
            }
        }
    }
    for(int i=0;i<=n;i++){
        dp2[i][0]=dp5[i][0]=INF;
        dp2[0][i]=dp5[0][i]=INF;
    }
    dp2[1][1]=a2[1][1];
    dp5[1][1]=a5[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) continue;
            dp2[i][j]=min(dp2[i-1][j],dp2[i][j-1])+a2[i][j];
            dp5[i][j]=min(dp5[i-1][j],dp5[i][j-1])+a5[i][j];
        }
    }
    int ans=min(dp2[n][n],dp5[n][n]);
    bool ok=0;
    if(zi!=-1&&ans>1){
        ans=1;
        ok=1;
    }
    cout<<ans<<"\n";
    string path;
    if(ok){
        path.append(zi-1,'D');
        path.append(zj-1,'R');
        path.append(n-zi,'D');
        path.append(n-zj,'R');
    } else if(dp2[n][n]<dp5[n][n]){
        int u=n,v=n;
        while(u>1||v>1){
            if(u>1&&dp2[u][v]==dp2[u-1][v]+a2[u][v]){
                path.push_back('D');u--;
            } else {
                path.push_back('R');v--;
            }
        }
        reverse(path.begin(),path.end());
    } else {
        int u=n,v=n;
        while(u>1||v>1){
            if(u>1&&dp5[u][v]==dp5[u-1][v]+a5[u][v]){
                path.push_back('D');u--;
            } else {
                path.push_back('R');v--;
            }
        }
        reverse(path.begin(),path.end());
    }
    cout<<path<<"\n";
    return 0;
}

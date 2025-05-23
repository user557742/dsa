// cho bang n*n tren moi hang thuoc cot chon 1 so sao cho tich cua n so duoc chon la lon nhat
// tim hoan vi cac dan em sao cho moi nguoi lam nhiem vu dung 1 lan 
// dp[x] la xs lon nhat khi hoan thanh __builtin_popcount(x) nhiem vu boi cac thanh vien trong x
// chon them i chua co trong x vao thi tro thanh dp[y]
#include <iostream>
#include <cstdio>
using namespace std;
int getbit(int i,int x){
    return (x>>(i-1)) &1;
}
double a[21][21];
double dp[(1<<20)];
int n;
int main(){
    if(fopen("BOND.INP","r")){
        freopen("BOND.INP","r",stdin);
        freopen("BOND.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            double x;cin>>x;
            a[i][j]=x/100.0;
        }
    }

    dp[0]=1;
    for(int x=0;x<(1<<n);x++){
        int nv=__builtin_popcount(x)+1;
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            int y=x|(1<<(i-1));
            dp[y]=max(dp[x]*a[i][nv],dp[y]);
            //cout<<dp[x]<<" "<<dp[y]<<"\n";
        }
    }
    //for(int x=0;x<(1<<n);x++) cout<<dp[x]<<" ";
    cout<<fixed;
    cout.precision(6);
    cout<<dp[(1<<n)-1]*100.0;
}
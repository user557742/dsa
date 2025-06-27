/*
dp[i][j] trong luong lon nhat de mang dung j gia tri

*/


#include <iostream>

using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 101;
int n,w[maxn],v[maxn],gt;
bool ok[100001];
long long dp[100001];
int main(){
    int s=0;
    cin>>n>>gt;
    rei(i,1,n) cin>>w[i]>>v[i];
    rei(i,1,n) s+=v[i];
    ok[0]=1;
    rei(i,1,n){
        for(int j=s;j>=0;j--){
            if(j>=v[i]) ok[j]=max(ok[j],ok[j-v[i]]);
        }
    }
    rei(j,1,s) dp[j]=1e18;
    rei(i,1,n){
        for(int j=s;j>=0;j--) if(j>=v[i]&&ok[j-v[i]]) dp[j]=min(dp[j-v[i]]+w[i],dp[j]);
    }
    int ds=0;
    rei(j,0,s){
        rei(i,1,n){
            if(dp[j]<=gt&&ok[j]) ds=max(ds,j) ;
        }
    }
    cout<<ds;
}
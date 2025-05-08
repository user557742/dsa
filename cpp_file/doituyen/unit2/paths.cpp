#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =501;
const int mod = 998244353;
#define mp make_pair
#define pb push_back
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
int dp[21][21][8001];
int n,k;
int a[501][501];
void sub1(){
    dp[1][1][a[1][1]]=1;
    int limx=1;
    rei(i,1,n) rei(j,1,n) if(a[i][j]!=-1) limx*=a[i][j];
    rei(i,1,n) rei(j,1,n) rei(x,1,limx){
        if(a[i+1][j]!=-1){
            dp[i+1][j][ x*a[i+1][j] ] =(dp[i+1][j][ x*a[i+1][j] ] +dp[i][j][x])%mod;
        }
        if(a[i][j+1]!=-1){
            dp[i][j+1][ x*a[i][j+1] ] =(dp[i][j+1][ x*a[i][j+1] ]+dp[i][j][x])%mod;
        }

    }
    ll ds=0;
    rei(i,0,limx) if(i%k==0) ds=(ds+dp[n][n][i])% mod;
    cout<<ds;
}
int dp1[501][501][21];
void sub2(){
    dp1[1][1][a[1][1]%k]=1;
    rei(i,1,n){
        rei(j,1,n){
            rei(x,0,k-1){
                if(a[i+1][j]!=-1) dp1[i+1][j][ (x*a[i+1][j])%k ] = (dp1[i+1][j][ (x*a[i+1][j])%k ]+dp1[i][j][x])%mod;
                if(a[i][j+1]!=-1) dp1[i][j+1][ (x*a[i][j+1])%k ] = (dp1[i][j+1][ (x*a[i][j+1])%k ]+dp1[i][j][x])%mod;

            }
        }
    }
    cout<<dp1[n][n][0];
}
ll dp2[501][501][201];
int d[101];
int tt[100001];
void sub4(){
    int m=0;
    for(int i=1;i*i<=k;i++){
        if(k%i==0){
            m++;
            d[m]=i;
            int t=k/i;
            if(t==i) continue;
            m++;
            d[m]=t;
        }
    }
    sort(d+1,d+m+1);
    dp2[1][1][lower_bound(d+1,d+m+1,__gcd(a[1][1],k))-d]=1;
    rei(i,1,n){
        rei(j,1,n){
            rei(x,1,m){
                if(a[i+1][j]!=-1){
                    int g=d[x];
                    int ng=__gcd(g*__gcd(a[i+1][j],k),k);
                    int nx=lower_bound(d+1,d+m+1,ng)-d;
                    dp2[i+1][j][nx]=(dp2[i+1][j][nx]+dp2[i][j][x])%mod;
                }
                if(a[i][j+1]!=-1){
                    int g=d[x];
                    int ng=__gcd(g*__gcd(a[i][j+1],k),k);
                    int nx=lower_bound(d+1,d+m+1,ng)-d;
                    dp2[i][j+1][nx]=(dp2[i][j+1][nx]+dp2[i][j][x])%mod;
                }
            }
        }
    }
    cout<<dp2[n][n][m];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    rei(i,1,n) rei(j,1,n) cin>>a[i][j];
    sub4();
    return 0;
}

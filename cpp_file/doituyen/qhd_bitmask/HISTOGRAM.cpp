#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n;
int h[16];
int dp[1<<N][16];
int dem[1<<N][16];
#define rei(i,a,b) for(int i=a;i<=b;i++)
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    while(cin>>n){
        if(n==0) return 0;
        rei(i,1,n) cin>>h[i];
        rei(x,0,(1<<n)-1) rei(i,1,n){
            dp[x][i]=0;
            dem[x][i]=0;
        }
        rei(i,1,n){
            dp[1<<(i-1)][i]=2*h[i]+2;
            dem[1<<(i-1)][i]=1;
        }
        
        rei(x,0,(1<<n)-1){
            rei(i,1,n) if(getbit(i,x)){
                rei(j,1,n) if(!getbit(j,x)){
                    int y=x|(1<<(j-1));
                    int tong=dp[x][i]-h[i]+2+abs(h[i]-h[j])+h[j];
                    if(dp[y][j]==tong) dem[y][j]+=dem[x][i];
                    if(tong>dp[y][j]){
                        dp[y][j]=max(dp[y][j],tong);
                        dem[y][j]=dem[x][i];
                    }
                }
            }
        }
        int ds=0;
        int cnt=0;
        rei(x,0,(1<<n)-1){
            rei(i,1,n){
                if(ds==dp[x][i]) cnt+=dem[x][i];
                if(ds<dp[x][i]){
                    ds=dp[x][i];
                    cnt=dem[x][i];
                }
            } 
        }
        cout<<ds<<" "<<cnt<<"\n";
    }
}
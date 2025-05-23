#include <iostream>
#include <cstring>
const int mod =1e9+7;
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 2001;
ll dp[maxn][2][2][2];
bool vis[maxn][2][2][2];
typedef long long ll;
int d,m,n;
int calc(int pos,int t,bool t0,int xh,int ons,string x){
    if(pos>(int)x.size()) return (xh&&(!ons));
    if(vis[pos][t][xh][ons]) return dp[pos][t][xh][ons];
    int lim=(t) ? (x[pos-1]-'0') : 9;
    ll ds=0; 
    rei(i,0,lim){
        int nt=(t&&(lim==i));
        int idx=(int)x.size()-pos+1;
        int nt0=(t0&&(i==0)) ;
        if(d==0&&t0){
            ds+=calc(pos+1,nt,nt0,0,0);
        } 
        else{
            int nxh=(xh||d==i);
            int nons=(ons||(idx%2==0));
            ds+=calc(pos+1,nt,nt0,nxh,nons,x);
        }
    }
    vis[pos][t][nxh][nons]=1;
    dp[pos][t][nxh][nons]=ds;
    return ds;
}
ll f(string x){
    memset(vis,0,sizeof(vis));
    return calc(1,1,1,0,0);
}
int main(){

}
#include <iostream>
#include <cstring>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 2001;
const int mod=1e9+7; 
typedef long long ll;
ll dp[maxn][2][maxn];
bool vis[maxn][2][maxn];
int d,m;
ll calc(int pos,int t,int r,string &x){
    if(pos>(int)x.size()) return (r==0);
    if(vis[pos][t][r]) return dp[pos][t][r];
    int lim=(t) ? (x[pos-1]-'0') : 9;
    ll ds=0;
    rei(i,0,lim){
        int nt=(t&&(i==lim));
        int nr=(10*r+i)%m;
        if(pos%2==1&&i==d) continue;
        if(pos%2==0&&i!=d) continue;
        ds=(ds+calc(pos+1,nt,nr,x))%mod;
    }
    vis[pos][t][r]=1;
    dp[pos][t][r]=ds;
    return ds;
}
bool check( string &x) {
    int rem = 0;
    int n = x.size();
    for (int pos = 1; pos <= n; ++pos) {
        int dig = x[pos-1] - '0';
        if (pos % 2 == 1) {
            if (dig == d) return false;
        } else {
            if (dig != d) return false;
        }
        rem = (rem * 10 + dig) % m;
    }
    return rem == 0;
}

ll f(string x){
    memset(vis,0,sizeof(vis));
    return calc(1,1,0,x);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>d;
    string a,b;cin>>a>>b;
    cout<< (f(b)-f(a)+check(a)+mod)%mod;
}
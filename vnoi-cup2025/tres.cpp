#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[16][2][10][16];
bool vis[16][2][10][16];
ll calc(int pos,int t,int ld,int cnt,string x){
    if(pos>(int)x.size()) return 0;
    if(vis[pos][t][ld][cnt]) return dp[pos][t][ld][cnt];
    ll ds=0;
    int lim=(t) ? (x[pos-1]-'0') : 9;
    for(int i=0;i<=lim;i++){
        int nt=(t&&(i==lim));
        if(i==ld){
            ds+=calc(pos+1,nt,i,cnt+1,x)+1ll*ld*2*cnt+1ll*ld;
        }
        else ds+=calc(pos+1,nt,i,1,x)+1ll*ld;
    }
    vis[pos][t][ld][cnt]=1;
    dp[pos][t][ld][cnt]=ds;
    return ds;
}
ll f(ll a){
    string x=to_string(a);
    memset(vis,0,sizeof(vis));
    return calc(1,1,0,0,x);
}
int main(){
    ll a,b;cin>>a>>b;
    cout<<f(b)-f(a-1);
}
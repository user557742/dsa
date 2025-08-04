#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10][2][2][9][2001];
bool vis[10][2][2][9][2001];
ll f(int pos,int t,int lz,int ss0,int d,string x){
    if(pos>(int)x.size()) return d==1+1000;
    if(vis[pos][t][lz][ss0][d]) return dp[pos][t][lz][ss0][d];
    ll ds=0;
    int lim=(t) ? (x[pos-1]-'0') : 9;
    for(int i=0;i<=lim;i++){
        int nt=(t&&i==lim);
        int nlz=(lz&&(i==0));
        if(nlz==0){
            if((pos-ss0+1)%2==0) ds+=f(pos+1,nt,nlz,ss0,d-i,x);
            else ds+=f(pos+1,nt,nlz,ss0,d+i,x);
        }
        else ds+=f(pos+1,nt,nlz,ss0+1,d,x);
    }
    vis[pos][t][lz][ss0][d]=1;
    dp[pos][t][lz][ss0][d]=ds;
    return ds;
}
ll calc(string x){
    memset(vis,0,sizeof(vis));
    return f(1,1,1,0,1000,x);
}
int main(){
    if(fopen("CHUAN1.INP","r")){
        freopen("CHUAN1.INP","r",stdin);
        freopen("CHUAN1.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    string u=to_string (a),v=to_string(b);
    if(a==0) cout<<calc(v);
    else cout<<calc(v)-calc(u);
    return 0;
}

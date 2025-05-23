#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
const int mod=1e9+7;
#define rei(i,a,b) for(int i=(a);i<=(b);i++)
int dp[maxn][2][3];
bool vis[maxn][2][3];
int calc(int pos,int t,int s,string &x){
    if(pos>(int)x.size()) return (s==0);
    if(vis[pos][t][s]) return dp[pos][t][s];
    int lim=(t) ? (x[pos-1]-'0') : 9;
    int ds=0;
    rei(i,0,lim){
        int nt=(t&&(lim==i));
        int ns=(s+i*i)%3;
        ds=(ds+calc(pos+1,nt,ns,x))%mod;
    }
    vis[pos][t][s]=1;
    dp[pos][t][s]=ds;
    return ds;
}
int f(string &x){
    memset(vis,0,sizeof(vis));
    return calc(1,1,0,x);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    string x;
    while(t--){
        cin>>x;
        int tmp=0;
        for(char s:x) tmp=(tmp+(s-'0')*(s-'0'))%3; 
        cout<<f(x)-(tmp%3==0)<<"\n";
    }
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
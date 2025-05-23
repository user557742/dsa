#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int e[18*9+1];
ll dp[19][2][18*9+1];
bool vis[19][2][18*9+1];
ll calc(int pos,int t,int s,string x){
    if(pos>(int)x.size()) return (e[s]==s);
    if(vis[pos][t][s]) return dp[pos][t][s];
    int lim= (t) ? (x[pos-1]-'0') : 9;
    ll ds=0;
    rei(i,0,lim){
        int nt=(t&&lim==i);
        ds+=calc(pos+1,nt,s+i,x);
    }
    vis[pos][t][s]=1;
    dp[pos][t][s]=ds;
    return ds;
}
ll f(string x){
    memset(vis,0,sizeof(vis));
    return calc(1,1,0,x);
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    rei(i,2,18*9) e[i]=i;
    for(int i=2;i*i<=18*9;i++) if(e[i]==i) for(int j=i;j<=9*18;j+=i) e[j]=i;
    int T;cin>>T;
    while(T--){
        ll u,v;cin>>u>>v;
        string x=to_string(u-1);
        string y=to_string(v);
        if(u==0) cout<<f(y)<<"\n";
        else cout<<f(y)-f(x)<<"\n";
    }


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
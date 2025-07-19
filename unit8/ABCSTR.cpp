#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
typedef long long ll;
int n;
string s;
ll sa[maxn],sb[maxn],sc[maxn];
int main(){
    if(fopen("ABCSTR.INP","r")){
        freopen("ABCSTR.INP","r",stdin);
        freopen("ABCSTR.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1];
        sb[i]=sb[i-1];
        sc[i]=sc[i-1];
        if(s[i]=='A') sa[i]++;
        if(s[i]=='B') sb[i]++;
        if(s[i]=='C') sc[i]++;
    }
    map<pair<ll,ll>,ll> mp;
    mp[{0,0}]=1;
    for(int i=1;i<=n;i++){
        ll da=sa[i]-sb[i];
        ll db=sa[i]-sc[i];
        mp[{da,db}]++;
    }
    long long  ds=0;
    for(pair<pair<int,int>,int> x:mp){
        ds+=1ll*x.second*(x.second-1)/2;
    }
    cout<<ds;
}
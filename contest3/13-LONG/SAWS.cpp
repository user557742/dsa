#include <bits/stdc++.h>
using  namespace std;
const int maxn = 1e6+1;
int n,k;
typedef long long ll;
ll h[maxn],m[maxn];
ll s[maxn];
ll f(int x){
    int i=upper_bound(h+1,h+1+n,x)-h;
    return s[n]-s[i-1]-1ll*x*(n-i+1);
}
void bs(ll p,int lo,int hi){
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(f(mid)>=p) lo=mid;
        else hi=mid;
    }
    cout<<lo<<" ";
}
int main(){
    if(fopen("SAWS.INP","r")){
        freopen("SAWS.INP","r",stdin);
        freopen("SAWS.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++ ) cin>>h[i];
    for(int i=1;i<=k;i++) cin>>m[i];
    sort(h+1,h+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+h[i];
    int lo=0,hi=h[n]+1;
    for(int i=1;i<=k;i++) bs(m[i],lo,hi);
}

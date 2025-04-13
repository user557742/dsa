// st table
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn =1e6+1;
ll n,p;
ll a[maxn];
ll st[16][maxn];
ll s[maxn];
pair<ll,int> tmp[maxn];
int getans(int u,int v){
    int i=__lg(v-u+1);
    return max(st[i][u],st[i][v-(1<<i)+1]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>p;
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) tmp[i]={s[i],i};
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;i++) st[0][i]=tmp[i].second;
    int lim=__lg(n);
    for(int k=1;k<=lim;k++){
        for(int i=1;i+(1<<k)-1<=n;i++) st[k][i]=max(st[k-1][i],st[k-1][i+(1<<(k-1))]);
    }
    int ds=0;
    for(int i=1;i<=n;i++){
        ll ns=p+s[i-1];
        int j=lower_bound(tmp+1,tmp+n+1,make_pair(ns,0))-tmp;
        if(j>n) continue;
        if(tmp[j].first>=ns) ds=max(ds,getans(j,n)-i+1);
    }
    if(ds==0) cout<<-1;
    else cout<<ds;
    return 0;
}
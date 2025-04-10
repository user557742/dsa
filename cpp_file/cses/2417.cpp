#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int e[maxn];
int n;
int a[maxn];
vector<int> snt;
int gt[maxn];
const int mod= 1e9+7;
typedef long long ll;
ll bpow(ll u,ll v){
    ll ds=1;
    while(v>0){
        if(v%2) ds=(ds*u)%mod;
        u=(u*u)%mod;
        v/=2;
    }
    return ds;
}
ll c(ll u,ll v){
    ll ms=gt[v-u]*gt[u];
    ms%=mod;
    return (gt[v]*bpow(ms,mod-2))%mod;
}
bool ok[maxn];
int cnt=0;
int main(){
    cin>>n;
    /*gt[0]=1;
    for(int i=1;i<=n;i++) gt[i]=(gt[i-1]*i)%mod;*/
    for(int i=1;i<=n;i++) cin>>a[i];
    int lim=0;
    for(int i=1;i<=n;i++) lim=max(lim,a[i]);
    for(int i=2;i<=lim;i++) e[i]=i;
    for(int i=2;i*i<=lim;i++) if(e[i]==i) for(int j=i;j<=lim;j+=i) e[j]=i;
    for(int i=2;i<=lim;i++) if(e[i]==i) snt.push_back(i);
    int maxgt=0;
    for(int i=1;i<=n;i++) maxgt=max(maxgt,e[a[i]]);
    int nl=lower_bound(snt.begin(),snt.end(),maxgt)-snt.begin();
    ll ds=0;
   // cout<<"******************\n";
    //cout<<" "<<snt[nl]<<"\n";
    for(int i=0;i<=nl;i++){
        if(cnt>=n) break;
        ll dem=0;
        for(int j=1;j<=n;j++) if((a[j]%snt[i]==0)){
           // cout<<a[j]<<" ";

            dem++;
            cnt++;
        }
        //cout<<"\n";
        ds+=dem*(dem-1)/2;
    }
    cout<<n*(n-1)/2-ds;
} 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 5e5+1;
const int mod =1e9+7;
typedef long long ll;
int n,q;
ll a[maxn];
int e[maxn];
ll bpow(ll a,ll b){
    ll ds=1;
    while(b>0){
        if(b%2) ds=(ds*a)%mod;
        a=(a*a)%mod;
        b/=2;
    }
    return ds;
}
ll tinhtong(ll x){
    ll ds=1;
    while(x>1){
        int cnt=0;
        int p=e[x];
        while(x%p==0){
            cnt++;
            x/=p;
        }
        ll ts=bpow(p,2*(cnt+1))-1;
        ll ms=bpow(p,2)-1;
        ll gt=(ts*bpow(ms,mod-2))%mod;
        ds*=gt;
    }
    return ds;
}
ll calc(){
    ll ds=0;
    rei(i,1,n){
        rei(j,i+1,n){
            ll d=__gcd(a[i],a[j]);
            ll t=tinhtong(d);
            ll g=((a[i]/d)*(a[j]/d))%mod;
            ds=(ds+(g*t)%mod)%mod;
        }
    }
    return ds;
}
void capnhat(int x,int y){
    a[x]=y;
}
void snt(){
    rei(i,2,maxn-1) e[i]=i;
    for(int i=2;i*i<maxn;i++) if(e[i]==i) for(int j=i;j<maxn;j+=i) e[j]=i;
}
int main(){
    if(fopen("GCDS.INP","r")){
        freopen("GCDS.INP","r",stdin);
        freopen("GCDS.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    snt();
    cin>>n>>q;
    rei(i,1,n) cin>>a[i];
    cout<<calc()<<"\n";
    while(q--){
        int x,u;
        cin>>x>>u;
        capnhat(x,u);
        cout<<calc()<<"\n";
    }
}
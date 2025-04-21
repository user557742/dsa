#include <bits/stdc++.h>
using namespace std;
const int lim=1e6+1;
const int N=1e3+1;
const int mod=1e9+7;
typedef long long ll;
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ub upper_bound
int n;
ll getbit(int i,ll x){
    return (x>>(i-1))&1;
}
ll a[N];
void sub1(){
    if(n<2){
        cout<<0;
        return ;
    }
    ll ds=__gcd(a[1],a[2]);
    cout<<((ds==1) ? 0 : 2);
}
pair<ll,int> dp[1<<18];
void sub2(){
    for(int i=1;i<=n;i++){
        ll x=1<<(i-1);
        dp[x]={a[i],1};
    }
    for(int x=1;x<(1<<n);x++){
        for(int j=1;j<=n;j++) if(!getbit(j,x)){
            ll y=x|(1<<(j-1));
            ll tmp=__gcd(a[j],dp[x].first);
            if(tmp!=1) dp[y]={tmp,dp[x].second+1};
        }
    }
    int ds=0;
    rei(x,0,(1<<n)-1) ds=max(ds,dp[x].second);
    cout<<ds;
}
int e[lim];
void sub3(){
    rei(i,2,lim-1) e[i]=i;
    for(int i=2;i*i<lim;i++) if(e[i]==i) for(int j=i;j<lim;j+=i) e[j]=i;
    map<int,int> mp;
    rei(i,1,n){
        int cur=0;
        while(a[i]>1){
            if(cur!=e[a[i]]){
                cur=e[a[i]];
                mp[cur]++;
            }
            else{
                a[i]/=e[a[i]];
            }
        }
    }
    int ds=0;
    for(pair<int,int> x:mp){
        ds=max(ds,x.second);
    }
    cout<<ds;
}
vector<pair<ll,int>> qhd[N];
void sub4(){
    int ds=0;
    rei(i,1,n) if(a[i]%2==0) ds++;
    int ds1=0;
    rei(i,1,n) if(a[i]%3==0) ds1++;
    int ds2=0;
    rei(i,1,n) if(a[i]%5==0) ds2++;
    int ds3=0;
    rei(i,1,n) if(a[i]%7==0) ds3++;
    int ds4=0;
    rei(i,1,n) if(a[i]%11==0) ds4++;
    int ds5=0;
    rei(i,1,n) if(a[i]%13==0) ds5++;
    cout<<max({ds,ds1,ds2,ds3,ds4,ds5});
}
int main(){
	faster
    cin>>n;
    ll dsdd=0;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n) dsdd=max(dsdd,a[i]);
    if(n<=2) sub1();
    else if(n<=18) sub2();
    else if(dsdd<lim) sub3();
    else sub4();
	return 0;
}

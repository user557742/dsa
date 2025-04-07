#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n,H;
typedef long long ll;
struct bo{
    int h,w,s;
} a[N+1];
long long dp[1<<20];
bool cmp(bo u,bo v){
    if(u.s==v.s) return make_pair(u.w,u.h)>make_pair(v.w,v.h);
    return u.s>v.s;
}
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
bool check(int x,int j){
    long long gg=a[j].w;
    for(int i=n;i>=1;i--) if(getbit(i,x)){
        if(a[i].s-gg<0) return 0; 
    }
    return 1;
}
ll calc(int x){
    ll ds=1e18;
    ll gg=0;
    for(int i=n;i>=1;i--) if(getbit(i,x)){
        ds=min(ds,a[i].s-gg);
        gg+=a[i].w;
    }
    return ds;
}
int main(){
    if(fopen("guard.in","r")){
        freopen("guard.in","r",stdin);
        freopen("guard.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>H;
    for(int i=1;i<=n;i++) cin>>a[i].h>>a[i].w>>a[i].s;
    sort(a+1,a+n+1,cmp);
    for(int x=0;x<(1<<n);x++){
        for(int j=1;j<=n;j++) if(!getbit(j,x)){
            if(check(x,j)){
                int y=x|(1<<(j-1));
                dp[y]=dp[x]+a[j].h;
            }
        }
    }
    ll ds=-1;
    for(int x=0;x<(1<<n);x++) if(dp[x]>=H) ds=max(ds,calc(x));
    if(ds==-1||ds==1e18) cout<<"Mark is too tall";
    else cout<<ds; 
}
#include <bits/stdc++.h>
using namespace std;
int n,H;
const int N = 20;
long long dp[1<<N];
int h[N+1],w[N+1],s[N+1];
struct dhq{
    int hh,ww,ss;
}p[N+1];
bool cmp(dhq u,dhq v){
    if(u.ss==v.ss) return make_pair(u.ww,u.hh)<make_pair(v.ww,v.hh);
    return u.ss<v.ss;
}
int getbit(int i,int x){
    return (x>>(i-1))&1;
}
bool ok(int x,int j){
    vector<pair<long long ,long long>> tmp;
    for(int i=1;i<=n;i++) if(getbit(i,x)&&i!=j) tmp.push_back({s[i],w[i]});
    sort(tmp.begin(),tmp.end());
    long long gw=0;
    for(auto y:tmp){
        gw+=y.second;
        if(y.first-gw-w[j]<0) return 0;
        
    }
    return 1;
}
long long calc(long long x){
    vector<pair<long long ,long long>> tmp;
    for(int i=1;i<=n;i++) if(getbit(i,x)) tmp.push_back({s[i],w[i]});
    //sort(tmp.begin(),tmp.end());
    long long gw=0;
    long long ds=1e18;
    for(auto y:tmp){
        gw+=y.second;
        ds=min(ds,y.first-gw);
    }
    return ds;
}
int main(){
    cin>>n>>H;
    for(int i=1;i<=n;i++) cin>>p[i].hh>>p[i].ww>>p[i].ss;
    sort(p+1,p+n+1,cmp);
    for(int i=1;i<=n;i++){
        h[i]=p[i].hh;
        w[i]=p[i].ww;
        s[i]=p[i].ss;
    }
    dp[0]=0;
    for(int i=1;i<=n;i++) dp[1<<(i-1)]=h[i];
    for(int x=1;x<(1<<n);x++){
        for(int i=1;i<=n;i++) if(!getbit(i,x)){
            if(ok(x,i)){
                int y=x|(1<<(i-1));
                dp[y]=max(dp[y],dp[x]+h[i]);
            }
        }
    }
    long long ds=0;
    
    for(int x=0;x<(1<<n);x++) if(dp[x]>=H){
        cout<<x<<" "<<calc(x)<<"\n";
        ds=max(ds,calc(x));
    }
    if(ds==0) cout<<"Mark is too tall";
    
    else cout<<ds;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 501;
ll s[maxn];
pair<int,int> f(ll a[],int n,int A,int B){
    for(int i=1;i<=n;i++) s[i]=0;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++) s[i]*=2;
    pair<int,int> ds={1e9,0};
    for(int i=1;i<=n;i++) if(A<=a[i]&&a[i]<=B) ds={B-A,a[i]};
    for(int i=1;i<=n;i++){
        ll t=s[i-1]+A+B;
        int j1=lower_bound(s+i,s+n+1,t)-s;
        int j2=upper_bound(s+i,s+n+1,t)-s-1;
        if(j1<=n&&s[j1]-t>=0) ds=min(ds,{s[j1]-t,(s[j1]-s[i-1])/2});
        if(j2>=1&&t-s[j2]>=0) ds=min(ds,{t-s[j2],(s[j2]-s[i-1])/2});
    }
    return ds;
}
int b[maxn][maxn];
ll a[maxn];
int n,m,A,B;
int main(){
    if(fopen("RMINDIST.inp","r")){
        freopen("RMINDIST.inp","r",stdin);
        freopen("RMINDIST.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>A>>B;
    if(A>B) swap(A,B);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
    pair<int,int> ds={1e9,0};
    for(int l=1;l<=m;l++){
        memset(a,0,sizeof(a));
        for(int r=l;r<=m;r++){
            for(int i=1;i<=n;i++) a[i]+=b[i][r];
            ds=min(ds,f(a,n,A,B));
        }
    }
    cout<<ds.second;
}
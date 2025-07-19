#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 501;
ll s[maxn];
int f(ll a[],int n,int A,int B){
    for(int i=1;i<=n;i++) s[i]=0;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ll ds=1e18;
    for(int i=1;i<=n;i++) if(A<=a[i]&&a[i]<=B) ds=B-A;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ll x=s[j]-s[i-1];
            ds=min(ds,abs(A-x)+abs(B-x));
        }
    }
    return (int)ds;
}
int b[maxn][maxn];
ll a[maxn];
int n,m,A,B;
int main(){
    if(fopen("RMINDIST.inp","r")){
        freopen("RMINDIST.inp","r",stdin);
        freopen("RMINDIST.ans","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>A>>B;
    if(A>B) swap(A,B);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
    int ds=1e9;
    for(int l=1;l<=m;l++){
        memset(a,0,sizeof(a));
        for(int r=l;r<=m;r++){
            for(int i=1;i<=n;i++) a[i]+=b[i][r];
            ds=min(ds,f(a,n,A,B));
        }
    }
    cout<<ds;
}
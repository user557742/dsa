#include <bits/stdc++.h>
using namespace std;
const int maxn = 401;
int h[maxn];
int l[maxn],r[maxn];
int calc(int n){
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    for(int i=1;i<=n;i++){
        int j=i-1;
        while(h[j]>=h[i]&&j>0) j=l[j];
        l[i]=j;
    }
    for(int i=n;i>=1;i--){
        int j=i+1;
        while(h[j]>=h[i]&&j<=n) j=r[j];
        r[i]=j; 
    }
    for(int i=1;i<=n;i++){
        r[i]-=1;
        l[i]+=1;
    }
    int ds=0;
    for(int i=1;i<=n;i++) if(h[i]!=0) ds=max(ds,2*(h[i]+(r[i]-l[i]+1)));
    return ds;
}
int n,m;
string a[maxn];
int main(){
    if(fopen("DINNER.INP","r")){
        freopen("DINNER.INP","r",stdin);
        freopen("DINNER.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) a[i]=" "+a[i];
    int ds=0;
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a[i][j]=='.') h[i]=h[i]+1;
            else h[i]=0;
            
        }
        ds=max(ds,calc(n));
    }
    cout<<ds-1;
}
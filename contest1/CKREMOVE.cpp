#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int a[maxn];
int n,k;
typedef long long ll;
int f[maxn];
int cnt[maxn];
void sub1(){
    ll ds=0;
    int ok=0;
    for(int l=1;l<=n;l++){
        memset(f,0,sizeof(f));
        memset(cnt,0,sizeof(cnt));
        ok=0;
        for(int r=l;r<=n;r++){
            int cu=f[a[r]];
            int moi=cu+1;
            f[a[r]]=moi;
            if(1<=cu&&cu<=k) if(--cnt[cu]==0) ok--;
            if(1<=moi&&moi<=k) if(cnt[moi]++==0) ok++;
            if(ok==k) ds++; 
        }
    }
    cout<<ds;
}
int ss=0;
inline void add(int x){
    int t=f[x]++;
    if(t==0) ss++;
    else if(t==1) ss--;
}
inline void del(int x){
    int t=f[x]--;
    if(t==1) ss--;
    else if(t==2) ss++;
}
void sub3(){
    ll ans=0;
    int r=1;
    for(int l=1;l<=n;l++){
        while(r<n&&ss==0) add(a[r++]);
        if(ss==0) break;
        ans+=1ll*(n-r+2);
        del(a[l]);
    }
    cout<<ans;
}
int main(){
    if(fopen("CKREMOVE.INP","r")){
        freopen("CKREMOVE.INP","r",stdin);
        freopen("CKREMOVE.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=3000) sub1();
    else sub3();
}
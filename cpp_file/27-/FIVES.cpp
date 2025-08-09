#include <bits/stdc++.h>
using namespace std;
const int maxn  = 2e3+1;
int n,q;
int a[maxn];
int ds[maxn][maxn];
struct it{
    int s[maxn];
    void init(){
        for(int i=1;i<=n;i++) s[i]=0;
    }
    void upd(int i,int x){
        for(;i<=n;i+=(i&(-i))) s[i]+=x;
    }
    int getans(int i){
        int ans=0;
        for(;i>0;i-=(i&(-i))) ans+=s[i];
        return ans;
    }
    int get(int l,int r){
        return getans(r)-getans(l-1);
    }
};
int tmp[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) tmp[i]=a[i];
    sort(tmp+1,tmp+n+1);
    for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
    for(int l=1;l<=n;l++){
        it ti,tj,tk;
        ti.init();tj.init();tk.init();
        for(int x=l+1;x<=n;x++){
            ds[l][x]=tk.get(1,a[x]-1);
            if(a[x]<a[l]) ti.upd(a[x],1);
            tj.upd(a[x],ti.get(1,a[x]-1));
            tk.upd(a[x],tj.get(a[x]+1,n));
        }
    }
    while(q--){
        int l,r;cin>>l>>r;
        cout<<ds[l][r]<<"\n";
    }
    return 0;
}

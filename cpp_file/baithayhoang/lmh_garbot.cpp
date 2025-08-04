#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+1;
int n,m;
int r[maxn],x[maxn];
int vis[maxn];
bool f(int sl){
    int j=1;
    for(int i=1;i<=n&&j<=m;i++){
        int p=r[i];
        int k=j;
        while(k<=m){
            ll L=x[j],R=x[k],ds=0;
            if(p<=L) ds=R-p;
            else if(p>=R) ds=p-L;
            else ds=min(2*(p-L)+(R-p),(p-L)+2*(R-p));
            if(ds>sl) break;
            k++;
        }
        j=k;
    }
    return j>m;
}
void bs(){
    int lo=0,hi=1;
    while(!f(hi)){
        lo=hi;
        hi*=2;
    }
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(f(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=m;i++) cin>>x[i];
    sort(r+1,r+n+1);
    sort(x+1,x+m+1);
    bs();
    return 0;
}
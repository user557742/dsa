#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
int n,q;
int a[maxn];
int cnt[maxn];
long long ds=0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        int u,v;cin>>u>>v;
        cnt[u]++;
        cnt[v+1]--;
    }
    for(int i=1;i<=n;i++) cnt[i]+=cnt[i-1];
    sort(cnt+1,cnt+n+1);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--) ds+=1ll*cnt[i]*a[i];
/*    for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";*/
    cout<<ds;
    return 0;
}

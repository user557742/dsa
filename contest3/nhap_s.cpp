#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n;
int a[maxn];
typedef long long ll;
int calc(int u,int v,ll x){
    int ds=0;
    for(int i=u;i<=v;i++) if(a[i]<=x) ds++;
    return ds;
}
int main(){
    if(fopen("tmp.in","r")){
        freopen("tmp.in","r",stdin);
        freopen("tmp.ans","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int q;cin>>q;
    while(q--){
        int u,v,x;cin>>u>>v>>x;
        cout<<calc(u,v,x)<<"\n";
    }
}
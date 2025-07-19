#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,q,a[maxn];
int main(){
    if(fopen("SALARYQR.inp","r")){
        freopen("SALARYQR.inp","r",stdin);
        freopen("SALARYQR.ans","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        char l;cin>>l;
        if(l=='!'){
            int k,x;cin>>k>>x;
            a[k]=x;
        }
        else{
            int u,v;cin>>u>>v;
            int ds=0;
            for(int i=1;i<=n;i++) if(a[i]>=u&&a[i]<=v) ds++;
            cout<<ds<<"\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,q;
int a[maxn];
void sub1(){
    int u,v;cin>>u>>v;
    int ds=0;
    for(int i=u;i<v;i++){
        for(int j=i+1;j<=v;j++){
            ds^=(a[i]+a[j]);
        }
    }
    cout<<ds<< "\n";
}
int main(){
    if(fopen("SUMXOR.INP","r")){
        freopen("SUMXOR.INP","r",stdin);
        freopen("SUMXOR.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--){
        sub1();
    }
}

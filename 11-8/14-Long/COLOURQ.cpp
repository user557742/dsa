#include <bits/stdc++.h>
using namespace std;
const int maxm=1e5+1;
int n,m;
int h[maxm];
long long s[maxm];
int main(){
    if(fopen("COLOURQ.INP","r")){
        freopen("COLOURQ.INP","r",stdin);
        freopen("COLOURQ.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>h[i];
    for(int i=1;i<=m;i++) s[i]=s[i-1]+h[i];
    int q;cin>>q;
    while(q--){
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        int j=lower_bound(h+x,h+u+1,y)-h;
        int t=lower_bound(h+x,h+u+1,v)-h;
        long long ds1=(s[u]-s[j-1])-(u-j+1)*(y-1);
        long long ds2=(s[u]-s[t-1])-(u-t+1)*v;
        cout<<ds1-ds2<<"\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxm=1e5+1;
int n,m;
int h[maxm];
int main(){
    if(fopen("COLOURQ.INP","r")){
        freopen("COLOURQ.INP","r",stdin);
        freopen("COLOURQ.ANS","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>h[i];
    int q;cin>>q;
    while(q--){
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        long long ds1=0;
        long long ds2=0;
        for(int i=x;i<=u;i++){
            if(h[i]>=y) ds1+=h[i]-y+1;
            if(h[i]>=v) ds2+=h[i]-v;
        }
        cout<<ds1-ds2<<"\n";
    }
    return 0;
}

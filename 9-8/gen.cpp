#include <bits/stdc++.h>
using namespace std;
int rd(int l,int r){
    int t=(r-l+1);
    return l+rand()%t;
}
int main(){
    freopen("INCCELLS.INP","w",stdout);
    srand(time(0));
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n=rd(1,100),m=rd(1,100),d=rd(1,min(m,n));
    cout<<n<<" "<<m<<" "<<d<<"\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<rd(1,1000000)<<" ";
        }
        cout<<"\n";
    }
}

#include <bits/stdc++.h>
using namespace std;
int rd(int l,int r){
    int t=(r-l+1);
    return l+rand()%t;
}
const int maxn = 1e5+1;
int n;
int a[maxn];
int q;
int u,v,x;
int main(){
    freopen("tmp.in","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(0));   
    n=rd(1,1000);
    cout<<n<<"\n";
    for(int i=1;i<=n;i++) a[i]=rd(1,1000000),cout<<a[i]<<" ";
    cout<<"\n";
    q=rd(1,1000);
    cout<<q<<"\n";
    while(q--){
        u=rd(1,n);
        v=rd(u,n);
        x=rd(1,1000000);
        cout<<u<<" "<<v<<" "<<x<<"\n";
    }
}
#include<bits/stdc++.h>
using namespace std;
int rd(int l,int r){
    int t=(r-l+1);
    return l+rand()%t;
}
string qe="!?";
int main(){
    freopen("SALARYQR.inp","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(0));
    int n=rd(2,1000),q=rd(2,1000);
    cout<<n<<" "<<q;
    cout<<"\n";
    for(int i=1;i<=n;i++){
        int x=rd(1,1000000);
        cout<<x<<" ";
    }
    cout<<"\n";
    while(q--){
        int l=rd(0,1);
        cout<<qe[l]<<" ";
        if(l==0){
            int k=rd(1,n),x=rd(1,100000);
            cout<<k<<" "<<x<<"\n";
        }
        else{
            int u=rd(1,1000000),v=rd(u,1000000);
            cout<<u<<" "<<v<<"\n";
        }
    }
}
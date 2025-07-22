#include <bits/stdc++.h>
using namespace std;
int rd(int l,int r){
    int t=(r-l+1);
    return l+rand()%t;
}
int main(){
    freopen("in.inp","w",stdout);
    srand(time(0));
    int t=rd(1,10);
    cout<<t<<"\n";
    while(t--){
        int n=rd(1,20),m=rd(1,20);
        cout<<n<< " "<< m<< "\n";
        while(n--) cout<<rd(1,1e9)<<" ";
        cout<<"\n";
        while(m--) cout<<rd(1,1e9)<< " ";
        cout<<"\n";
    }
}

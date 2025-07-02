#include <bits/stdc++.h>
using namespace std;
int randr(int l,int r){
    int t=r-l+1;
    return l+rand()%(t+1);
}
int main(){
    freopen("SEARCH.INP","w",stdout);
    srand(time(0));
    int m=randr(1,200);
    int n=randr(1,m);
    cout<<n<<" "<<m;
}
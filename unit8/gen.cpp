#include <bits/stdc++.h>
using namespace std;
int rd(int l,int r){
    int t=(r-l+1);
    return l+rand()%t;
}
string seed="ABC";
int main(){
    freopen("bnum.inp","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    srand(time(0));
    int n=rd(1,10);
    while(n--){
        int x=rd(1,20);
        int y=rd(0,9);
        cout<<x<<" "<<y<<"\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int e[maxn];
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll l,r;cin >>l>>r;
    ll n=r/l;
    int i=2,ds=0;
    while(i*i<=n){
        if(n%i==0){
            n/=i;
            ds++;
        }
        else  i++;
    }
    cout<<ds+(n>0)+1;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn =1e6+1;
ll a,b;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>a>>b;
    int d=__gcd(a,b);
    int a1=a/d;
    int b1=b/d;
    ll s=b1*a1;
    int lim=sqrt(s);
    int x1=1,y1=1;
    for(int i=lim;i>0;i--){
        if(s%i==0){
            x1=i;
            y1=s/i;
            if(__gcd(x1,y1)==1) break;
        }
    }
    //y1=s/x1;
    cout<<1ll*x1*d<<" "<<1ll*y1*d;
    return 0;
}
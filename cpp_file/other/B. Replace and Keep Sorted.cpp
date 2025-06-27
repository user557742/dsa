/*
    
*/
#include <iostream>
using namespace std;
typedef long long ll;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 1e5+1;
int n,k,q;
int a[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q>>k;
    rei(i,1,n) cin>>a[i];
    while(q--){
        int l,r;cin>>l>>r;
        cout<<k-a[r]+a[l]-1+2*((a[r]-a[l]+1)-(r-l+1))<<"\n";
    }
}
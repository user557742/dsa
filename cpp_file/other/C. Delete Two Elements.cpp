#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 2e5+1;
int n;
int a[maxn];
void solve(){
    cin>>n;
    rei(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    long long s=0;
    rei(i,1,n) s+=a[i];
    s*=2;
    if(s%n!=0) cout<<"0\n";
    else{
        s=s/n;
        long long ds=0;
        rei(i,1,n-1){
            int l=lower_bound(a+i+1,a+n+1,s-a[i])-a;
            int r=upper_bound(a+i+1,a+n+1,s-a[i])-a-1;
            
            ds+=r-l+1;
        }
        cout<<ds<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
}
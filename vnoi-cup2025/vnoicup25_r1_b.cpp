#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m;
void  solve(){
    cin>>n>>m;
    /*if(n==m) {
        cout<<"0\n";
        return ;
    }*/
    if(m<n){
        cout<<"-1\n";
        return ;
    }
    vector<ll> ans;
    while(n<m){
        if(m%n!=0){
            cout<<"-1\n";
            return ;
        }
        ll k=m/n;
        ll t=__gcd(n,k);
        if(t==1){
            cout<<"-1\n" ;
            return ;
        }
        else{
            n*=t;
            ans.push_back(t);
        }
    }
    cout<<ans.size()<<" ";
    for(int x:ans) cout<<x<<" ";
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
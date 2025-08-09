#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+1;
int n;
int a[maxn];
ll s[maxn];
ll x;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll ds=0;
    map<ll,int> mp;
    cin>>n>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n;i>=1;i--){
        ds+=mp[s[i-1]+x];
        mp[s[i]]++;
    }
    cout<<ds;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int n,x;
int a[maxn];
typedef long long ll;
ll s[maxn];
bool check(int i){
    int j=lower_bound(s,s+n+1,2*s[i])-s;
    if(j>n) return 0;
    return s[n]-s[j]>=(s[j]-s[i]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    for(int i=n;i>=0;i--) if(check(i)){
        cout<<s[i];
        return 0;
    }
    return 0;
}
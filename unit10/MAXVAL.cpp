#include <bits/stdc++.h>
using namespace std;
const int maxn  = 2e5+1;
int n;
int a[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ds=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++) if(a[j]<a[i]) ds=max(ds,a[i]%a[j]);
    }
    cout<<ds;
}   
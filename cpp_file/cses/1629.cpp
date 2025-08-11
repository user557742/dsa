#include <bits/stdc++.h>
using namespace std;
const int maxn  = 1e6+1;
struct ev{
    int bd,kt;
} a[maxn];
int n;
bool cmp(ev u,ev v){
    return make_pair(u.kt,u.bd)<make_pair(v.kt,v.bd);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].bd>>a[i].kt;
    sort(a+1,a+n+1,cmp);
    int ds=0;
    int r=0;
    for(int i=1;i<=n;i++){
        if(r<=a[i].bd){
            ds++;
            r=a[i].kt;
        }
    }
    cout<<ds;
    return 0;
}

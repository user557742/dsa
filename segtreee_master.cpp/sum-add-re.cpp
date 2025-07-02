#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n;
int a[maxn];
typedef long long ll;
struct node{
    ll s=0,lz=0;
    node(ll _s=0,ll _lz=0) : s(_s),lz(_lz) {}
};
node com(node u,node v){
    return node(u.s+v.s,0);
}
struct IT{
    node g[4*maxn];
    void pull(int r){
        g[r]=com(g[2*r],g[2*r+1]);
    }
    void apply(int r,int lo,int hi){
        for
    }
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
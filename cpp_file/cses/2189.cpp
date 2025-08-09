#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct p{
    ll x,y;
    p(ll _x=0,ll _y=0) : x(_x),y(_y) {}
};
ll cross(p u,p v){
    return u.x*v.y-u.y*v.x;
}
p vec(p u,p v){
    return p(v.x-u.x,v.y-u.y);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    p a,b,c;
    int t;cin>>t;
    while(t--){
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        p ab=vec(a,b);
        p ac=vec(a,c);
        ll ds=cross(ab,ac);
        if(ds==0) cout<<"TOUCH\n";
        if(ds<0) cout<<"RIGHT\n";
        if(ds>0) cout<<"LEFT\n";
    }
    return 0;
}

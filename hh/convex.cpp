#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n;
struct p{
    double x=0,y=0;
    p(double _x=0,double _y=0) : x(_x),y(_y) {}
} a[maxn];
bool cmp(p u,p v){
    return make_pair(u.x,u.y) < make_pair(v.x,v.y);
}
p vec(p u , p v){
    return p(v.x-u.x,v.y-u.y);
}
double cross(p u,p v){
    return u.x*v.y-u.y*v.x;
}
bool cw(p a,p b,p c){
    p ab = vec(a,b);
    p bc = vec(b,c);
    return cross(ab,bc)<=0;
}
double dis(p u,p v){
    return sqrt((u.x-v.x)*(u.x-v.x)+(u.y-v.y)*(u.y-v.y));
}
double cv(vector<p> dg){
    double ds=0;
    for(int i=0;i<=(int)dg.size()-2;i++) ds+=dis(dg[i],dg[i+1]);
    ds+=dis(dg[dg.size()-1],dg[0]);
    return ds;
}
double S(vector<p> dg){
    double ds=0;
    p p1=dg[0];
    for(int i=1;i<=(int)dg.size()-2;i++) ds+=0.5*abs(cross(vec(p1,dg[i]),vec(p1,dg[i+1])));
    return ds;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1,cmp);
    vector<p> ch;
    for(int i=1;i<=n;i++){
        while(ch.size()>=2&&cw(ch[ch.size()-2],ch[ch.size()-1],a[i])) ch.pop_back();
        ch.push_back(a[i]);
    }
    int t=ch.size();
    for(int i=n-1;i>=2;i--){
        while(ch.size()>t&&cw(ch[ch.size()-2],ch[ch.size()-1],a[i])) ch.pop_back();
        ch.push_back(a[i]);
    }
    //for(p s:ch ) cout<<s.x<<" "<<s.y<<"\n";
    cout<<fixed;
    cout.precision(6);
    cout<<cv(ch)<<"\n"<<S(ch)<<"\n";
}

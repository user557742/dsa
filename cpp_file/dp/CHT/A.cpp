#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
typedef long long ll;
typedef double db;
const ll inf = 1e18;
struct line{
    ll a=0,b=0;
    mutable db p=0;
    line(ll _a=0,ll _b=0,db _p=0) : a(_a),b(_b),p(_p) {}
    bool operator < (const line o) const {
        if(o.a==inf&&o.b==inf) return p<o.p;
        return a<o.a;
    }
};
typedef multiset<line>::iterator mli;
struct LC{
    multiset<line> lc;
    bool isect(mli x,mli y){
        if(y==lc.end()){
            x->p=inf;
            return ;
        }
        if(x->a==y->a) x->p=(x->b > y->b) ? inf:-inf;
        else x->p=1.0*(y->b-x->b)/(x->a-y->a);
        return x->p >= y->p;
    }
    void add(ll a,ll b){
        mli x=lc.insert(line(a,b,0)),y=next(x);
    }
};
int main(){

}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
const ll inf = 1e18 ;
const int maxn = 5e5+1;
int n,q;
struct que{
    int l=0,r=0,id=0;
}tv[maxn];
int a[maxn],tmp[maxn];
int sz;
inline int gbl(int i){
    return (i%sz==0) ? i/sz : i/sz+1;
}
inline bool cmp(const que &u, const que &v){
    int bu = gbl(u.l), bv = gbl(v.l);
    if (bu == bv) return u.r < v.r;
    return bu < bv;
}

int ans=0;
int ds[maxn];
int cnt[maxn];
inline void add(int pos) {
    int v = a[pos];
    if      (cnt[v] == 1) ans++;   // 1 ? 2
    else if (cnt[v] == 2) ans--;   // 2 ? 3
    cnt[v]++;
}

inline void del(int pos) {
    int v = a[pos];
    if      (cnt[v] == 2) ans--;   // 2 ? 1
    else if (cnt[v] == 3) ans++;   // 3 ? 2
    cnt[v]--;
}

inline int getans(){
    return ans;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    sz=sqrt(n);
    // nen mang a
    rei(i,1,n) cin>>a[i];
    rei(i,1,n) tmp[i]=a[i];
    sort(tmp+1,tmp+n+1);
    rei(i,1,n) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
    // doc truy van
    rei(i,1,q){
        cin>>tv[i].l>>tv[i].r;
        tv[i].id=i;
    }
    sort(tv+1,tv+q+1,cmp);
    int cl=1,cr=0;
    rei(i,1,q){
        que x=tv[i];
        while(cl>x.l) add(--cl);
        while(cl<x.l) del(cl++);
        while(cr<x.r) add(++cr);
        while(cr>x.r) del(cr--);
        ds[x.id]=getans();
    }
    rei(i,1,q) cout<<ds[i]<<"\n";
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 2e5+1;
int n,m;
ll a[maxn],tmp[maxn];
ll cnt[maxn];
ll ds[maxn];
ll ans=0;
inline int gbl(int x){
	int sz=sqrt(n);
	return (x%sz==0) ? x/sz:x/sz+1;
}
struct que{
	int l=0,r=0,id=0;
}tv[maxn];
inline bool cmp(que u,que v){
	if(gbl(u.l)==gbl(v.l)) return u.r<v.r;
	return gbl(u.l)<gbl(v.l);
}
inline void add(int x){
	ans+=(2*cnt[a[x]]+1)*tmp[a[x]];
	cnt[a[x]]++;
}
inline void del(int x){
	ans+=(-2*cnt[a[x]]+1)*tmp[a[x]];
	cnt[a[x]]--;
}
inline ll getans(){
	return ans;
}
int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>m;
	rei(i,1,n) cin>>a[i];
	rei(i,1,m){
		cin>>tv[i].l>>tv[i].r;
		tv[i].id=i;
	}
	rei(i,1,n) tmp[i]=a[i];
	sort(tmp+1,tmp+n+1);
	sort(tv+1,tv+m+1,cmp);
	rei(i,1,n) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
	int cl=1,cr=0;
for (int i = 1; i <= m; i++) {
    que &x = tv[i];      // ch? truy v?n 1..m
    while (cl > x.l) add(--cl);
    while (cr < x.r) add(++cr);
    while (cl < x.l) del(cl++);
    while (cr > x.r) del(cr--);
    ds[x.id] = getans();
}

	rei(i,1,m) cout<<ds[i]<<"\n";
	return 0;
}


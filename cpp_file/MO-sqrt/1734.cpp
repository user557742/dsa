#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 2e5+1;
int n,q;
int a[maxn];
int tmp[maxn];
int sz;
inline int gb(int i){
	if(i%sz==0) return i/sz;
	return i/sz+1;
}
struct que{
	int l=0,r=0,id=0;
}tv[maxn];
bool cmp(que u, que v){
	if(gb(u.l)==gb(v.l)) return u.r<v.r;
	else return gb(u.l)<gb(v.l);
}
int ans=0;
int cnt[maxn];
inline void add(int x){
	if(cnt[a[x]]==0) ans++;
	cnt[a[x]]++;
}
inline void del(int x){
	cnt[a[x]]--;
	if(cnt[a[x]]==0) ans--;
}
inline int getans(){
	return ans;
}
int ds[maxn];
int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>q;
	sz=sqrt(n);
	rei(i,1,n) cin>>a[i];
	// nen mang 
	rei(i,1,n) tmp[i]=a[i];
	sort(tmp+1,tmp+n+1);
	rei(i,1,n) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
	//doc truy van
	rei(i,1,q){
		cin>>tv[i].l>>tv[i].r;
		tv[i].id=i;
	}
	//  ss truy van 
	sort(tv+1,tv+q+1,cmp);
	int cl=1,cr=0;
	for(que x:tv){
		while(cl>x.l) add(--cl);
		while(cl<x.l) del(cl++);
		while(cr>x.r) del(cr--);
		while(cr<x.r) add(++cr);
		ds[x.id]=getans();
	}
	rei(i,1,q) cout<<ds[i]<<"\n";
	return 0;
}


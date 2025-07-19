#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 1e5+1;
int n,sz;
int a[maxn];
int tmp[maxn];
int cnt[maxn];
inline int gbl(int l){
	return (l%sz==0) ? l/sz : l/sz+1; 
}
struct que{
	int l=0,r=0,id=0;
} tv[maxn];
bool cmp(que u,que v){
	if(gbl(u.l)==gbl(v.l)) return u.r<v.r;
	return gbl(u.l)<gbl(v.l);
}
struct it{
	pair<int,int> g[4*maxn];
	void upd(int k,int x,int r=1,int lo=1,int hi=n){
		if(lo==hi){
			g[r].first+=x;
			g[r].second=lo;
			return ;
		}
		int mid=(lo+hi)/2;
		if(k<=mid) upd(k,x,2*r,lo,mid);
		else upd(k,x,2*r+1,mid+1,hi);
		g[r]=max(g[2*r],g[2*r+1]);
	}
	pair<int,int> get(int u,int v,int r=1,int lo=1,int hi=n){
		if(u>hi||v<lo) return {-1e9,-1e9};
		if(u<=lo&&hi<=v) return g[r];
		int mid=(lo+hi)/2;
		return max(get(u,v,2*r,lo,mid),get(u,v,2*r+1,mid+1,hi));
	}
}t;
void add(int x){
	t.upd(a[x],1);
}
void del(int x){
	t.upd(a[x],-1);
}
int getans(){
	return t.get(1,n).first;
}
int ds[maxn];
int main(){
	int q;
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>q;
	sz=sqrt(n);
	rei(i,1,n) cin>>a[i];
	rei(i,1,n) tmp[i]=a[i];
	sort(tmp+1,tmp+n+1);
	rei(i,1,n) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
	rei(i,1,q){
		cin>>tv[i].l>>tv[i].r;
		tv[i].l++;
		tv[i].r++;
		tv[i].id=i;
	}
	sort(tv+1,tv+q+1,cmp);
	int cl=1,cr=0;
	for(que x:tv){
		while(cl > x.l) add(--cl);  
		while(cr < x.r) add(++cr);  
		while(cl < x.l) del(cl++);  
		while(cr > x.r) del(cr--);  
		ds[x.id]=getans();
	}
	rei(i,1,q) cout<<ds[i]<<"\n";
	return 0;
	
}


#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 1e5+1;
int n;
int a[maxn],tmp[maxn];
/*
tinh tong a[j] lon hon i tinh tong, j lon hon i tinh tong j*a[j] lon hon i
th1 : i<j . a[i]<a[j]
	(j-i)*(a[j]-a[i]) = j*a[j]+a[i]*i-a[j]*i-a[i]*j;
	ds+=splhti[i]+a[i]*i*cntplh[i]-i*splht[i]-a[i]*splhi[i];
th2 : i<j . a[i]>a[j]
	(j-i)*(a[i]-a[j]) = j*a[i]-a[j]*j-a[i]*i+i*a[j];
	ds+=a[i]*spnhi[i]-spnhti[i]-a[i]*i*cntpnh[i]+spnht[i]*i;
th3 : i>j . a[i]<a[j]
	(i-j)*(a[j]-a[i]) = i*a[j]-i*a[i]-j*a[j]+j*a[i];
	ds+=i*stlht[i]-i*a[i]*cnttlh[i]-stlhti[i]+a[i]*stlhi[i]; 
th4 : i>j . a[i]>a[j]
	(i-j)*(a[i]-a[j]) = i*a[i]+a[j]*j-a[j]*i-a[i]*j;
	ds+=i*a[i]*cnttnh[i]+stnhti[i]-i*stnht[i]-a[i]*stnhi[i];
*/
ll splhti[maxn],splht[maxn],splhi[maxn],cntplh[maxn];
ll stlhti[maxn],stlht[maxn],stlhi[maxn],cntpnh[maxn];
ll spnhti[maxn],spnht[maxn],spnhi[maxn],cnttlh[maxn];
ll stnhti[maxn],stnht[maxn],stnhi[maxn],cnttnh[maxn];
struct node{
	ll sti=0,st=0,si=0,cnt=0;
	node(ll _sti=0,ll _st=0,ll _si=0,ll _cnt=0) : sti(_sti),st(_st),si(_si),cnt(_cnt) {}
};
node com(node u,node v){
	return node(u.sti+v.sti,u.st+v.st,u.si+v.si,u.cnt+v.cnt);
}
struct it{
	node g[4*maxn];
	void upd(int k,node x,int r=1,int lo=1,int hi=n){
		if(lo==hi){
			g[r]=com(g[r],x);
			return ;
		}
		int mid=(lo+hi)/2;
		if(k<=mid) upd(k,x,2*r,lo,mid);
		else upd(k,x,2*r+1,mid+1,hi);
		g[r]=com(g[2*r],g[2*r+1]);
	}
	node get(int u,int v,int r=1,int lo=1,int hi=n){
		if(u>hi||v<lo) return node(0,0,0);
		if(u<=lo&&hi<=v) return g[r];
		int mid=(lo+hi)/2;
		return com(get(u,v,2*r,lo,mid),get(u,v,2*r+1,mid+1,hi));
	}
}lhp,nhp,nht,lht;
ll ds[maxn];
int main(){
	if(fopen("SEQ.INP","r")){
		freopen("SEQ.INP","r",stdin);
		freopen("SEQ.OUT","w",stdout);
	}
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n;
	rei(i,1,n) cin>>a[i];
	rei(i,1,n) tmp[i]=a[i];
	sort(tmp+1,tmp+n+1);
	rei(i,1,n) a[i]=lower_bound(tmp+1,tmp+n+1,a[i])-tmp;
	// tt 
	red(i,n,1){
		node x=lhp.get(a[i],n);
		splhti[i]=x.sti;
		splht[i]=x.st;
		splhi[i]=x.si;
		cntplh[i]=x.cnt;
		node y=nhp.get(1,a[i]-1);;
		spnhti[i]=y.sti;
		spnht[i]=y.st;
		spnhi[i]=y.si;
		cntpnh[i]=y.cnt;
		nhp.upd(a[i],node(tmp[a[i]]*i,tmp[a[i]],i,1));
		lhp.upd(a[i],node(tmp[a[i]]*i,tmp[a[i]],i,1));
	}
	rei(i,1,n){
		node x=lht.get(a[i], n);
		stlhti[i]=x.sti;
		stlht[i]=x.st;
		stlhi[i]=x.si;
		cnttlh[i]=x.cnt;
		node y=nht.get(1,a[i]-1);
		stnhti[i]=y.sti;
		stnht[i]=y.st;
		stnhi[i]=y.si;
		cnttnh[i]=y.cnt;
		nht.upd(a[i],node(tmp[a[i]]*i,tmp[a[i]],i,1));
		lht.upd(a[i],node(tmp[a[i]]*i,tmp[a[i]],i,1));
	}
	rei(i,1,n){
		ll A=splhti[i]+tmp[a[i]]*i*cntplh[i]-i*splht[i]-tmp[a[i]]*splhi[i];
		ll B=tmp[a[i]]*spnhi[i]-spnhti[i]-tmp[a[i]]*i*cntpnh[i]+spnht[i]*i;
		ll C=i*stlht[i]-i*tmp[a[i]]*cnttlh[i]-stlhti[i]+tmp[a[i]]*stlhi[i]; 
		ll D=i*tmp[a[i]]*cnttnh[i]+stnhti[i]-i*stnht[i]-tmp[a[i]]*stnhi[i];
		ds[i]=A+B+C+D;
	}
	rei(i,1,n) cout<<ds[i]<<" ";
	return 0;
}


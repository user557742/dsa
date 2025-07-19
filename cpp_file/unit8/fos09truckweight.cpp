#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 2e5+1;
ll n,k;
ll a[maxn];
bool f(ll x){
	ll cnt=0;
	ll g=0;
	rei(i,1,n) {
		if(g+a[i]>x){
			cnt++;
			g=a[i];
		}
		else g+=a[i];
	}
	if(g>0) cnt++;
	return cnt<=k;
}
void bs(){
	ll lo=oo,hi=0;
	rei(i,1,n) {
		lo=min(lo,a[i]);
		hi+=a[i];
	}
	while(lo+1<hi){
		ll mid=(lo+hi)/2;
		if(f(mid)) hi=mid;
		else lo=mid;
	}
	cout<<hi;
}
int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>k;
	rei(i,1,n) cin>>a[i];
	bs();
	return 0;
}


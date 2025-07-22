#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
#define gcd __gcd
const int maxn = 2e5+1;
int g[maxn];
int n,q;
int a[maxn];
int st[21][maxn];
int gg(int l, int r) {
    if (l > r) return 0;
    int k = __lg(r - l + 1);
    return gcd(st[k][l], st[k][r - (1 << k) + 1]);
}

void ver1q(int l,int r,int x){
	ll cnt=0;
	rei(i,l,r){
		int f=a[i];
		rei(j,i,r){
			f=gcd(f,a[j]);
			if(f>=x) cnt++;
			else break;
		}
	}
	cout<<cnt<<"\n";
}
void ver2q(int l,int r,int x){
    ll ds = 0;
    rei(i,l,r){
        int lo = i, hi = r, pos = r + 1;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(gg(i, mid) >= x){
                lo = mid + 1;
            } else {
                pos = mid;
                hi = mid - 1;
            }
        }
        ds += (ll)(pos - i);
    }
    cout << ds << "\n";
}
int main(){
	if(fopen("GCD.INP","r")){
		freopen("GCD.INP","r",stdin);
		freopen("GCD.OUT","w",stdout);
	}
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>q;
	rei(i,1,n) cin>>a[i];
	rei(i,1,n) st[0][i]=a[i];
	int k=__lg(n);
	rei(i,1,k){
		for(int j=1;j+(1<<i)-1<=n;j++) st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	while(q--){
		int l,r,x;cin>>l>>r>>x;
		if(1ll*q*n*n<=1e6) ver1q(l,r,x);
		else ver2q(l,r,x);
	}	
	return 0;
}


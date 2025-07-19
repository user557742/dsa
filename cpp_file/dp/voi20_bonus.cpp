#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 3e2+1;
int n,k;
ll a[maxn];
ll dp[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
ll calc(int h, int l, int r) {
    if(h > k) return 0;
    if((r - l + 1) < 2 * (k - h + 1)) return -oo;
    if(vis[h][l][r]) return dp[h][l][r];
    ll ds = 0;
    if(l + 1 <= r) ds = max(ds, calc(h + 1, l + 2, r) + abs(a[l] - a[l + 1]));
    if(l <= r - 1) ds = max(ds, calc(h + 1, l, r - 2) + abs(a[r] - a[r - 1]));
    if(l < r) ds = max(ds, calc(h + 1, l + 1, r - 1) + abs(a[l] - a[r]));
    ds = max(ds, calc(h, l + 1, r));
    ds = max(ds, calc(h, l, r - 1));
    vis[h][l][r] = 1;
    return dp[h][l][r] = ds;
}

int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>k;
	rei(i,1,n) cin>>a[i];
	cout<<calc(1,1,n);
	return 0;
}


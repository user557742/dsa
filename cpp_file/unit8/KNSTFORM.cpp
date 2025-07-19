/*dp[i][j] trong luong nho phat khi chon trong i vat dau tien co gia tri khong nho hon j 
dp[i][j] = inf 
dp[i][0] = 0
dp[i][j] xet vat i+1 
neu dp[i][j]=min(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);*/
#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++) 
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 1e3+5;
int n,m;
int a[maxn],b[maxn];
ll dp[maxn][maxn*10+5];
int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>m;
	rei(i,1,n) cin>>a[i]>>b[i];
	ll lim=0;
	rei(i,1,n) lim+=b[i];
	rei(i,0,n) rei(j,0,lim) dp[i][j]=oo;
	dp[0][0]=0;
	rei(i,1,n){
		rei(j,0,lim){
			dp[i][j]=min(dp[i][j],dp[i-1][j]);
			if(j>=b[i]){
				dp[i][j]=min(dp[i][j],dp[i-1][j-b[i]]+a[i]);
			}
		}
	}
	/*rei(i,1,n){
		rei(j,0,lim) cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	int g=0;
	red(j,lim,0) if(dp[n][j]<=m){
		
		g=j;
		break;
	}
	vector<int> c;
	cout<<g<<"\n";
	red(i,n,1){
		if(g>=b[i]&&dp[i][g]==dp[i-1][g-b[i]]+a[i]){
			c.push_back(i);
			g-=b[i];	
		}
	}
	cout<<c.size()<<"\n";
	reverse(c.begin(),c.end());
	for(int x:c) cout<<x<<" ";
	return 0;
}\


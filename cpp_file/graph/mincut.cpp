#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 1001;
int a[maxn][maxn];
ll s[maxn][maxn];
int n,m,k;
bool fc(int x){
	
}
void solve(){
	int u,v,x,y;
	cin>>u>>v>>x>>y;
}

int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>m>>k;
	rei(i,1,n) rei(j,1,m) cin>>a[i][j];
	rei(i,1,n) rei(j,1,m) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	while(k--) solve();
	return 0; 
}


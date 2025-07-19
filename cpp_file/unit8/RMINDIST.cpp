#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,A,B;
const int maxn = 501;
int a[maxn][maxn];
int b[maxn][maxn];
ll x[maxn];
ll s[maxn];
#define rei(i,a,b) for(int i=a;i<=b;i++)
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>A>>B;
	if(A>B) swap(A,B);
	rei(i,1,n) rei(j,1,m) cin>>b[i][j];
	if(n>m){
		rei(i,1,n) rei(j,1,m) a[j][i]=b[i][j];
		swap(n,m);
	}
	else {
		rei(i,1,n) rei(j,1,m) a[i][j]=b[i][j];
	}
	pair<ll,ll> ds={1e18,1e18};
	for(int l=1;l<=n;l++){
		for(int i=1;i<=m;i++){
			x[i]=0;
			s[i]=0;
		} 
		for(int r=l;r<=n;r++){
			for(int i=1;i<=m;i++) x[i]+=a[r][i];
			for(int i=1;i<=m;i++) s[i]=s[i-1]+x[i]; 
			 for(int i=1;i<=m;i++){
				// tim j sao cho s[j]-s[i-1] >= A && s[j]-s[i-1] <= B
				// s[j]>=A+s[i-1] va s[j] <= B+s[i-1]
				int tmp=lower_bound(s+i,s+m+1,A+s[i-1])-s;
				int ok=upper_bound(s+i,s+m+1,B+s[i-1])-lower_bound(s+i,s+m+1,A+s[i-1]);
				if(ok>0){
					ds=min(ds,{B-A,s[tmp]-s[i-1]});
				}
				// tim j sao cho s[j]-s[i-1] <= A && s[j] - s[i-1] <=B
				// s[j] < A + s[i-1] 
				// de A+B-2*(s[j]-s[i-1]) min thi (s[j]-s[i-1]) max 
				// s[j] = max(s[i....n])
				// nguoxc lai thi thi la min 
				int j1=lower_bound(s+i,s+m+1,A+s[i-1])-s;
				if(j1!=m+1){
					j1--;
					ds=min(ds,{A+B-2*(s[j1]-s[i-1]),s[j1]-s[i-1]});
				} 
				// s[j] > B+s[i-1]
				int j2=upper_bound(s+i,s+m+1,B+s[i-1])-s;
				if(j2!=m+1){
					ds=min(ds,{2*(s[j2]-s[i-1])-A-B,s[j2]-s[i-1]});
				}
			}
		}
	}
	cout<<ds.first;
}
// o(n*n*m*log m)

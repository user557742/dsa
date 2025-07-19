#include <bits/stdc++.h>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define red(i,b,a) for(int i=b;i>=a;i--)
typedef long long ll;
const ll oo = 1e18;
const int maxn = 1e5+1;
int n;
int a[maxn];

(i-j)*(a[i]-a[j]) = a[i]*i-i*a[j]-j*a[i]+j*a[j]
tinh tong a[j] lon hon i tinh tong, j lon hon i tinh tong j*a[j] lon hon i
th1 : i<j . a[i]<a[j]
	(j-i)*(a[j]-a[i]) = j*a[j]+a[i]*i-a[j]*i-a[i]*j;
	ds+=splhti[i]+a[i]*i-i*splht[i]-a[i]*splhi[i];
th2 : i<j . a[i]>a[j]
	(j-i)*(a[i]-a[j]) = j*a[i]-a[j]*j-a[i]*i+i*a[j];
	ds+=a[i]*spnhi[i]-spnhti[i]-a[i]*j+i*spnht[i];
th3 : i>j . a[i]<a[j]
	(i-j)*(a[j]-a[i]) = i*a[j]-i*a[i]-j*a[j]+j*a[i];
	ds+=i*stlht[i]-i*a[i]-stlhti[i]+a[i]*stlhi[i]; 
th4 : i>j . a[i]>a[j]
	(i-j)*(a[i]-a[j]) = i*a[i]+a[j]*j-a[j]*i-a[i]*j;
	ds+=i*a[i]+stnhti[i]-i*stnht[i]-a[i]*stnhi[i];

int main(){
	ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n;
	rei(i,1,n) cin>>a[i];
	return 0;
}


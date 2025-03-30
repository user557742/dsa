#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n;
int a[maxn];
void solve(){
    int x=a[1];
    int y=a[1];
    rei(i,2,n){
        x=min(x,a[i]);
        y=max(y,a[i]);
    }
    int d=-x%(y-x);
    cout<<__gcd(x+d,y+d)<<"\n";
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        rei(i,1,n) cin>>a[i];
        solve();
    }


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
// nx : trong 1 day so a1,a2,a3,...,an thi gcd co co hoi la lon nhat khi khoang cach giua chung la kon nhat
// gcd(x,y) = gcd(x,y-x)
// gcd(x+d,y+d)=gcd(x+d,y-x) 
// chon d ge gcd(x+d,y+d) max thi d=y-x-x =>gcd(x+d,y+d)=y-x
// y-x la khoang cach nho nhat giua 2 so trong mang a
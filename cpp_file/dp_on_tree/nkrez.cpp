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
pair<int,int> a[maxn];
int n;
bool cmp(pair<int,int> u,pair<int,int> v){
    return mp(u.Y,u.X)<mp(v.Y,v.X);
}
ll dp[maxn];
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i].first >> a[i].second;
    sort(a+1,a+n+1,cmp);
    rei(i,1,n){
        dp[i]=max(dp[i-1],1ll*a[i].second-1ll*a[i].first);
        rei(j,1,i-1){
            if(a[j].second<=a[i].first){
                dp[i]=max(dp[j]+a[i].second-a[i].first,dp[i]);
            }
        }
    }
    cout<<dp[n];
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;

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
int d,n,st;
int a[maxn];
int x[maxn];
int ans=0;
void back(int k,int pos){
    if(k>d){
        int ds=0;
        rei(i,0,n-1) if(x[i]) ds+=a[i];
        ans=max(ans,ds);
        return ;
    }
    x[pos]=1;
    back(k+1,pos);
    x[pos]=0;
    if(pos>0) back(k+1,pos-1);
    if(pos<n-1) back(k+1,pos+1);
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>st>>d;
    rei(i,0,n-1) cin>>a[i];
    back(1,st);
    cout<<ans;
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
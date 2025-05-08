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
int n,m;
int a[maxn],b[maxn];
int main(){
    if(fopen("SPEEDING.INP","r")){
        freopen("SPEEDING.INP","r",stdin);
        freopen("SPEEDING.OUT","w",stdout);
    }
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int i=1;
    while(n--){
        int x,u;
        cin>>x>>u;
        while(x--){
            a[i]=u;
            i++;
        }
    }    
    i=1;
    while(m--){
        int x,u;cin>>x>>u;
        while(x--){
            b[i]=u;
            i++;
        }
    }
    int ds=0;
    rei(i,1,100) ds=max(ds,a[i]-b[i]);
    cout<<ds;

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
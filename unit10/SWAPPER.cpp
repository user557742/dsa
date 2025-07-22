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
int a[2*maxn];
int main(){
    if(fopen("in.inp","r")){
        freopen("in.inp","r",stdin);
        freopen("out.out","w",stdout);
    }
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,2*n) a[i]=i;
    int ds=n;
    int m;cin>>m;
    while(m--){
        int u,v;cin>>u>>v;
        if((u<=n&&v<=n)||(u>n&&v>n)){
            swap(a[u],a[v]);
            cout<<ds<<"\n";
            continue;
        }
        if(u<=n){
            if(v>n){
                if(a[u]<=n&&a[v]>n) ds--;
                if(a[u]>n&&a[v]<=n) ds++;
                swap(a[u],a[v]);
            }
            else swap(a[u],a[v]);
        }
        else{
            if(v>n) swap(a[u],a[v]);
            else{
                if(a[v]<=n&&a[u]>n) ds--;
                if(a[v]>n&&a[u]<=n) ds++;
                swap(a[u],a[v]);
            }
        }
        cout<<ds<<"\n";
    }

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
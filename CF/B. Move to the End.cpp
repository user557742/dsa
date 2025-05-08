// xet k phan tu cuoi neu doi cho thi khong thay doi gi ca
// ds=max(a[1],...,a[n-k])+a[n-k+1]+...+a[n];
// dung st table truy van o(1)
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
int st[20][maxn];
ll s[maxn];
void pep(){
    int lim=__lg(n);
    rei(i,1,n) st[0][i]=a[i];
    rei(i,1,lim){
        for(int j=1;j+(1<<i)-1<=n;j++) st[i][j]=max(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    } 
    rei(i,1,n) s[i]=s[i-1]+a[i];
}
ll getans(int l,int r){
    int i=__lg(r-l+1);
    return max(st[i][l],st[i][r-(1<<i)+1]);
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
        pep();
        rei(k,1,n){
            ll ds=s[n]-s[n-k];
            ds=max(ds,getans(1,n-k+1)+s[n]-s[n-k+1]);
            cout<<ds<<" ";
        }
        cout<<"\n";
    }


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
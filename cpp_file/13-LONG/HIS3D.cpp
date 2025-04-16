#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+1;
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
ii a[maxn];
int mx[20][maxn],my[20][maxn];
int Ra[maxn],Rb[maxn],La[maxn],Lb[maxn];
void build(){
    for(int i=1;i<=n;i++){
        mx[0][i]=a[i].X;
        my[0][i]=a[i].Y;
    }
    int lim=__lg(n);
    for(int i=1;i<=lim;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            mx[i][j]=min(mx[i-1][j],mx[i-1][j+(1<<(i-1))]);
            my[i][j]=min(my[i-1][j],my[i-1][j+(1<<(i-1))]);
        }
    }
}
void builda() {
    for (int k = 1; k <= n; k++) {
        int j = k - 1;
        while (a[j].X >= a[k].X && j > 0) {
            j = La[j]; 
        }
        La[k] = j;
    }
    for (int k = n; k >= 1; k--) {
        int j = k + 1;
        while (a[j].X >= a[k].X && j <= n) {
            j = Ra[j]; 
        }
        Ra[k] = j;
    }
}
void buildb() {
    for (int k = 1; k <= n; k++) {
        int j = k - 1;
        while (a[j].Y >= a[k].Y && j > 0) {
            j = Lb[j]; 
        }
        Lb[k] = j;
    }
    for (int k = n; k >= 1; k--) {
        int j = k + 1;
        while (a[j].Y >= a[k].Y && j <= n) {
            j = Rb[j]; 
        }
        Rb[k] = j;
    }
}
ll getx(int u,int v){
    int i=__lg(v-u+1);
    return min(mx[i][u],mx[i][v-(1<<i)+1]);
}
ll gety(int u,int v){
    int i=__lg(v-u+1);
    return min(my[i][u],my[i][v-(1<<i)+1]);
}
void sub2(){
    build();
    ll ds=0;
    rei(l,1,n){
        rei(r,l,n){
            ds=max(ds,getx(l,r)*gety(l,r)*(r-l+1));
        }
    }
    cout<<ds;
}
void sub3(){
    a[0].X=-1e9;
    a[n+1].X=1e9;
    a[0].Y=-1e9;
    a[n+1].Y=1e9;
    build();
    builda();
    buildb();
    ll ds=0;
    for(int i=1;i<=n;i++){
        ll l1=La[i]+1,r1=Ra[i]-1;
        ll l2=Lb[i]+1,r2=Rb[i]-1;
        ll ds1=(r1-l1+1)*a[i].X*gety(l1,r1);
        ll ds2=(r2-l2+1)*a[i].Y*getx(l2,r2);
        ds=max({ds,ds1,ds2});
    }
    cout<<ds;
}
int main(){
    if(fopen("HIS3D.INP","r")){
        freopen("HIS3D.INP","r",stdin);
        freopen("HIS3D.OUT","w",stdout);
    }
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].X>>a[i].Y;
    if(n<=2000) sub2();
    else sub3();
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
/*
5
5 3
4 4
2 1
3 2
1 5


3
5 6
4 6
5 1
*/
// greedy aproach :
// neu a[sz] > a[1] thanh day a[sz] tong la a[sz] 
// neu a[sz] < a[1] thanh day a[1] tong la a[1]
// neu a[sz]==a[1] day thanh chia ra 2 th backtracking
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
ll ds=0;
void back(vector<int> a){
    if(a.size()==1) return;
    vector<int> tmp1;
    vector<int> tmp2;
    ll ds1=0;
    ll ds2=0;
    rei(i,0,(int)a.size()-2){
        tmp1.push_back(a[i+1]-a[i]);
        ds1+=a[i+1]-a[i];
    }
    red(i,(int)a.size()-1,1){
        tmp2.push_back(a[i-1]-a[i]);
        ds2+=a[i-1]-a[i];
    }
    ds=max({ds,ds1,ds2});
    back(tmp1);
    back(tmp2);
}
void sub1(){
    ds=0;
    int n;cin>>n;
    vector<int> a;
    rei(i,1,n){
        int x;
        cin>>x;
        ds+=x;
        a.push_back(x);
    }
    back(a);
    cout<<ds<<"\n";
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        sub1();
    }


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 6e6+1;
const int maxn = 4e5+1;
int m=1;
int e[N];
long long snt[maxn];
void sangnt(){
    for(int i=2;i<N;i++) e[i]=i;
    for(int i=2;i*i<N;i++) if(e[i]==i) for(int j=i;j<N;j+=i) e[j]=i;
    for(int i=2;i<N;i++) if(e[i]==i){
        snt[m]=i;
        m++;
    }   
}bool cmp(int a,int b){
    return a>b;
}
int n;
int a[maxn];


void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int ans=0;
    long long sa=0,sb=0;
    for(int i=1;i<=n;i++){
        sa+=a[i];
        sb+=snt[i];
        if(sa>=sb) ans=i;
    }
    cout<<n-ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sangnt();
    int t;cin>>t;
    while(t--) solve();
}
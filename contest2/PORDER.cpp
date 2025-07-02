#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,a[maxn],b[maxn],q[maxn];
void sub4(){
    for(int i=1;i<=n;i++) a[i]=i;
    for(int i=n;i>=1;i--){
        
        for(int j=i-b[i];j<i;j++) swap(a[j],a[j+1]);
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
int fw[maxn];
void upd(int x, int v) {
    for (; x < maxn; x += x & -x) fw[x] += v;
}
int get(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) res += fw[x];
    return res;
}
int kth(int k) {
    int res = 0, sum = 0;
    for (int i = 18; i >= 0; --i) {
        int next = res + (1 << i);
        if (next < maxn && sum + fw[next] < k) {
            res = next;
            sum += fw[next];
        }
    }
    return res + 1;
}
int ds[maxn];
void sub5(){
    for (int i = 1; i <= n; ++i) a[i] = b[n + 1 - i];
    memset(fw,0,sizeof(fw));
    for (int i = 1; i <= n; ++i) upd(i, 1);
    for (int i = 1; i <= n; ++i) {
        int k = a[i] + 1;
        int pos = kth(k);
        q[i] = pos;
        upd(pos, -1);
    }
    for (int i = 1; i <= n; ++i) ds[i] = n + 1 - q[n + 1 - i];
    for (int i = 1; i <= n; ++i) cout << ds[i] << " ";
    cout<<"\n";
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    if(n<=5000) sub4();
    else sub5();
}

int main(){
    if(fopen("PORDER.INP","r")){
        freopen("PORDER.INP","r",stdin);
        freopen("PORDER.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
typedef long long ll;

ll dp[maxn][11];
int n,k;
int a[maxn];
ll s[maxn];   // prefix sum a
ll sw[maxn];  // prefix sum i * a[i]

// cost gom a[j..i] ve vi tri i
ll cost(int i, int j) {
    return (i+1)*(s[i]-s[j-1]) - (sw[i]-sw[j-1]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=1;i<=n;i++) {
        s[i] = s[i-1] + a[i];
        sw[i] = sw[i-1] + 1LL * a[i] * i;
    }

    // base case: gom tất cả về 1 nhóm
    for(int i=1;i<=n;i++) dp[i][1] = cost(i, 1);

    // dp[i][x] = gom a[1..i] thành x nhóm
    for(int x=2; x<=k; x++) {
        for(int i=1;i<=n;i++) dp[i][x] = 1e18;
        for(int i=x; i<=n; i++) {
            for(int j=x-1; j<i; j++) {
                dp[i][x] = min(dp[i][x], dp[j][x-1] + cost(i, j+1));
            }
        }
    }

    cout << dp[n][k] << "\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
typedef long long ll;
ll dp[maxn][11];
int n,k;
int a[maxn];
ll s[maxn];
ll sw[maxn];
// tong (i-j+1)*a[j]
// ds (i+1)*(s[j]-s[i])-(sw[j]-sw[i])
ll cost(int i, int j) {
    return (i+1)*(s[i-1]-s[j-1])-(sw[i-1]-sw[j-1]);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[n-i+1];
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        sw[i]=sw[i-1]+1ll*a[i]*i;
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<s[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<sw[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) dp[i][j]=1e18;
    for(int i=1;i<=n;i++){
        for(int x=1;x<=k;x++) if(i>=x){
            ll ds=1e18;
            for(int j=1;j<i;j++) if(j>=x){
                ds=min(ds,dp[j-1][x-1]+cost(i,j));
                cout<<j<<" "<<i<<" "<<cost(i,j)<<"\n";
            }
            dp[i][x]=min(ds,dp[i][x]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int x=1;x<=k;x++) if(i>=x) cout<<dp[i][x]<<" ";
        cout<<"\n";
    }
    cout<<dp[n][k];
    return 0;
}


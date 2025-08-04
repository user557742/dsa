#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e6+1;
ll a[maxn],P[maxn],d[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, h;
    cin >> n >> h;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        d[i] = (ll)(i+1) - a[i];
        P[i] = P[i-1] + d[i];
    }
    deque<int> dq;
    ll ans = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        while(!dq.empty() && d[dq.back()] >= d[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= h){
            int s = i - h + 1;
            while(dq.front() < s) dq.pop_front();
            ll mn = d[dq.front()];
            if(mn >= s){
                ll S = P[i] - P[s-1];
                ll ds = S - (ll)h * s;
                ans = min(ans, ds);
            }
        }
    }

    if(ans == LLONG_MAX) cout << -1;
    else cout << ans;
    return 0;
}

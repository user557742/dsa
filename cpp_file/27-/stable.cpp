#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int> l(n), d(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < n; i++) cin >> d[i];

    map<int, vector<int>> G;
    ll ds = 0;
    for(int i = 0; i < n; i++){
        G[l[i]].push_back(d[i]);
        ds += d[i];
    }

    priority_queue<int> pqr; 
    priority_queue<int, vector<int>, greater<int>> pqk; 
    ll sk = 0;    
    int cntl = 0;   

    ll ans = LLONG_MAX;
    for(auto &it : G){
        auto &v = it.second;
        int cntM = v.size();
        ll sm = 0;
        for(int x : v) sm += x;
        int k = min(cntl, cntM - 1);
        while((int)pqk.size() > k){
            int x = pqk.top(); pqk.pop();
            sk -= x;
            pqr.push(x);
        }
        while((int)pqk.size() < k && !pqr.empty()){
            int x = pqr.top(); pqr.pop();
            sk += x;
            pqk.push(x);
        }
        ll rm = ds - sm - sk;
        ans = min(ans, rm);
        for(int x : v){
            pqr.push(x);
            cntl++;
        }
    }
    cout << ans << "\n";
    return 0;
}

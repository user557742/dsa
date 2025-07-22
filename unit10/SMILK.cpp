#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int N;
    cin >> N;
    vector<pair<int,int>> bo(N);
    for(int i = 0; i < N; i++){
        int g, d;
        cin >> g >> d;
        bo[i] = {d, g};
    }

    sort(bo.begin(), bo.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto &c : bo){
        int d = c.first;
        int g = c.second;
        pq.push(g);
        if((int)pq.size() > d){
            pq.pop();
        }
    }

    ll ans = 0;
    while(!pq.empty()){
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";
    return 0;
}

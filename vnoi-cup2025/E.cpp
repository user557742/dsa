#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a, p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> L[i];
    for (int i = 0; i < n; i++) cin >> R[i];

    
    p = L;

    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[p[i]-1] = i;

    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x,int y){
        return a[x] == a[y] ? x < y : a[x] < a[y];
    });

    vector<int> vals(n);
    for (int i = 0; i < n; i++) vals[i] = pos[idx[i]];

    vector<int> lis(n,1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (vals[j] <= vals[i])
                lis[i] = max(lis[i], lis[j] + 1);

    vector<int> lds(n,1);
    for (int i = n-1; i >= 0; i--)
        for (int j = n-1; j > i; j--)
            if (vals[j] <= vals[i])
                lds[i] = max(lds[i], lds[j] + 1);

    int mx = 1;
    for (int i = 0; i < n; i++)
        mx = max(mx, lis[i] + lds[i] - 1);

    cout << n - mx << "\n";

    return 0;
}

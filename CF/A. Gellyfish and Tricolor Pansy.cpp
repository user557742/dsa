#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long x = min(a, c);
        long long y = min(b, d);
        if (x >= y) 
            cout << "Gellyfish\n";
        else 
            cout << "Flower\n";
    }
    return 0;
}

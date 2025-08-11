#include <bits/stdc++.h>
using namespace std;

// lấy số ngẫu nhiên trong [l, r], đảm bảo l <= r
int rd_int(int l, int r, mt19937 &rng) {
    if (l > r) return l; // fallback (không nên xảy ra nếu bạn set đúng ranges)
    uniform_int_distribution<int> dist(l, r);
    return dist(rng);
}

int main() {
    freopen("COLOURQ.INP","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937 rng((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());

    int m = rd_int(1, 1000, rng); // số cột
    int n = rd_int(1, 1000, rng); // chiều cao tối đa (range heights)
    cout << m << " " << n << "\n"; // LƯU Ý: chương của bạn đọc m rồi n

    // in dãy h[1..m] non-decreasing trong [0..n]
    int pre = 0;
    for (int i = 1; i <= m; ++i) {
        // đảm bảo không vượt quá n: chọn trong [pre, n]
        if (pre > n) pre = n;
        int x = rd_int(pre, n, rng);
        cout << x << (i == m ? '\n' : ' ');
        pre = x;
    }

    int q = rd_int(1, 1000, rng);
    cout << q << "\n";
    while (q--) {
        int x = rd_int(1, m, rng);
        int u = rd_int(x, m, rng);     // đảm bảo x <= u (chỉ số cột)
        int y = rd_int(1, n, rng);
        int v = rd_int(y, n, rng);     // đảm bảo y <= v (chiều cao) — tùy bạn có muốn tạo cả y>v hay không
        cout << x << " " << y << " " << u << " " << v << "\n";
    }
    return 0;
}

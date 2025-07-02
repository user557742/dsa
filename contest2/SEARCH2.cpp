#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int BIT[MAXN];

// Cập nhật BIT tại vị trí x với giá trị v
void update(int x, int v) {
    for (; x < MAXN; x += x & -x) BIT[x] += v;
}

// Tính tổng từ 1 đến x trong BIT
int get(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) res += BIT[x];
    return res;
}

// Tìm phần tử nhỏ nhất sao cho tổng <= k
int kth(int k) {
    int res = 0, sum = 0;
    for (int i = 18; i >= 0; --i) {
        int next = res + (1 << i);
        if (next < MAXN && sum + BIT[next] < k) {
            res = next;
            sum += BIT[next];
        }
    }
    return res + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<int> w(n + 1), e(n + 1), Q(n + 1), P(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> w[i];

        for (int i = 1; i <= n; ++i)
            e[i] = w[n + 1 - i];

        // Khởi tạo BIT
        fill(BIT, BIT + n + 2, 0);
        for (int i = 1; i <= n; ++i)
            update(i, 1);

        // Tạo hoán vị Q từ e
        for (int i = 1; i <= n; ++i) {
            int k = e[i] + 1;
            int pos = kth(k);
            Q[i] = pos;
            update(pos, -1);
        }

        // Tính P từ Q
        for (int i = 1; i <= n; ++i)
            P[i] = n + 1 - Q[n + 1 - i];

        // Xuất kết quả
        for (int i = 1; i <= n; ++i)
            cout << P[i] << (i < n ? ' ' : '\n');
    }

    return 0;
}  
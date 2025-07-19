#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Giới hạn theo đề: n ≤ 18, k ≤ 9
constexpr int MAX_N = 18;
constexpr int MAX_K = 9;
constexpr int MAX_SUM = MAX_N * MAX_K;  // 162

// dp[pos][delta + MAX_SUM][tight][lead_zero]
static ll dp[MAX_N][2*MAX_SUM+1][2][2];
static bool seen[MAX_N][2*MAX_SUM+1][2][2];

// Mảng lưu “giới hạn chữ số” khi tight = 1
static int limit_digit[MAX_N];
// Biến toàn cục cho chữ số lớn nhất K
static int K_glob;

// Đệ quy digit‑dp: đếm số KHÔNG CÂN BẰNG (delta != 0)
ll dfs(int pos, int delta, bool tight, bool lead_zero) {
    if (pos < 0) {
        return (delta != 0 ? 1LL : 0LL);
    }
    ll &res = dp[pos][delta + MAX_SUM][tight][lead_zero];
    if (seen[pos][delta + MAX_SUM][tight][lead_zero])
        return res;
    seen[pos][delta + MAX_SUM][tight][lead_zero] = true;
    res = 0;

    int up = tight ? limit_digit[pos] : K_glob;
    for (int d = 0; d <= up; ++d) {
        bool nt = tight && (d == up);
        bool nz = lead_zero && (d == 0);
        if (nz) {
            res += dfs(pos-1, delta, nt, true);
        } else {
            res += dfs(pos-1, delta + d, nt, false);
            res += dfs(pos-1, delta - d, nt, false);
        }
    }
    return res;
}

// Đếm số KHÔNG CÂN BẰNG có **đúng** len chữ số, dùng chữ số 0..K
ll count_exact_len(int len, int K) {
    K_glob = K;
    for (int i = 0; i < len; ++i)
        limit_digit[i] = K;
    memset(seen, 0, sizeof seen);
    return dfs(len-1, 0, true, true);
}

int main() {
    // Nếu tồn tại file bnum.inp, redirect I/O
    if (FILE *f = fopen("bnum.inp","r")) {
        fclose(f);
        freopen("bnum.inp","r", stdin);
        freopen("bnum.out","w", stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Tiền xử lý pre_exact[len][k]
    static ll pre_exact[MAX_N+1][MAX_K+1];
    for (int k = 0; k <= MAX_K; ++k) {
        for (int len = 1; len <= MAX_N; ++len) {
            pre_exact[len][k] = count_exact_len(len, k);
        }
    }

    // 2) Đọc truy vấn và in kết quả:
    // “có không quá n chữ số” = sum_{len=1..n} pre_exact[len][k]
    int n, k;
    while (cin >> n >> k) {
        ll ans = 0;
        for (int len = 1; len <= n; ++len)
            ans += pre_exact[len][k];
        cout << ans << "\n";
    }
    return 0;
}

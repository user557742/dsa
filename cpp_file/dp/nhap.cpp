#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int _n): n(_n), bit(n+1, 0) {}

    // Cập nhật tại vị trí i: +1 (chỉ làm 1 lần khi res[i]=1)
    void update(int i) {
        for (; i <= n; i += i & -i)
            bit[i] += 1;
    }

    // Tổng từ 1..i
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    // Tổng trên [l..r]
    int range_sum(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int main(){
    if(fopen("JUMP.INP","r")){
        freopen("JUMP.INP","r",stdin);
        freopen("JUMP.OUT","w",stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long K;
    cin >> n >> K;
    vector<long long> a(n), comp;
    comp.reserve(n * 3);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        comp.push_back(a[i]);
        comp.push_back(a[i] - K);
        comp.push_back(a[i] + K);
    }

    // 1) Nén giá trị
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    auto idx = [&](long long x) {
        // trả về 1-based index trong Fenwick
        return int(lower_bound(comp.begin(), comp.end(), x) - comp.begin()) + 1;
    };

    Fenwick fw(comp.size());
    vector<int> res(n, 0);

    // 2) Khởi đầu: hoa 0 luôn tới được
    res[0] = 1;
    fw.update(idx(a[0]));

    // 3) Duyệt i = 1..n-1
    for (int i = 1; i < n; i++) {
        // Xác định khoảng [a[i]-K, a[i]+K] trên mảng nén
        int L = int(lower_bound(comp.begin(), comp.end(), a[i] - K) - comp.begin()) + 1;
        int R = int(upper_bound(comp.begin(), comp.end(), a[i] + K) - comp.begin());
        
        // Nếu có bất kỳ j<i nào đã đánh dấu (sum>0) trong [L..R]
        if (fw.range_sum(L, R) > 0) {
            res[i] = 1;
            fw.update(idx(a[i]));
        }
    }

    // 4) In kết quả
    for (int x : res) cout << x << ' ';
    cout << '\n';
    return 0;
}

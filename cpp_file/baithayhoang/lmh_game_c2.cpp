#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1000000007;

int add(int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}
int sub(int a, int b) {
    a -= b;
    if (a < 0) a += MOD;
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    // dp[j] = coefficient of q^j ở bước hiện tại
    vector<int> dp(n+1, 0), b(n+1), c(n+1);
    dp[0] = 1;

    for(int i = 1; i <= m; i++){
        int shift = k + i;
        // 1) Nhân với (1 - q^{k+i})
        for(int j = 0; j <= n; j++){
            int without = dp[j];
            int with_shift = (j >= shift ? dp[j - shift] : 0);
            b[j] = sub(without, with_shift);
        }
        // 2) Chia cho (1 - q^i): c = b * (1 + q^i + q^{2i} + ...)
        //    tức c[j] = b[j] + (j>=i ? c[j-i] : 0)
        for(int j = 0; j <= n; j++){
            c[j] = b[j];
            if(j >= i) c[j] = add(c[j], c[j - i]);
        }
        // Copy về dp
        dp.swap(c);
    }

    cout << dp[n] << "\n";
    return 0;
}


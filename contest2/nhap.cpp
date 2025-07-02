#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // dp[i][j][k][0/1]
    vector<vector<vector<vector<int>>>> dp(
        M + 1, vector<vector<vector<int>>>(
            N + 1, vector<vector<int>>(
                M + 1, vector<int>(2, 0)
            )
        )
    );

    // Khởi tạo
    for (int i = 1; i <= M; i++) {
        int parity = (M - i) % 2;
        dp[i][1][i][parity] = 1;
    }

    // DP
    for (int i = 1; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= i; k++) {
                for (int x = 0; x < 2; x++) {
                    if (dp[i][j][k][x] == 0) continue;

                    // Không chọn ô i+1
                    dp[i + 1][j][k][x] += dp[i][j][k][x];

                    // Chọn ô i+1 (nếu j < N)
                    if (j < N) {
                        int diff = (i + 1) - k - 1;
                        int new_parity = (x + diff) % 2;
                        dp[i + 1][j + 1][i + 1][new_parity] += dp[i][j][k][x];
                    }
                }
            }
        }
    }

    // Kết quả: tổng dp[M][N][k][1] với mọi k
    int ans = 0;
    for (int k = 1; k <= M; k++) {
        ans += dp[M][N][k][1];
    }

    cout << ans << endl;
    return 0;
}
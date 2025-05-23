/*
dp[u][0] : so cap thoa man trong cay con goc u ma goc u dang trang
dp[u][1] : so cap thoa man trong cay con goc u ma u la mau den
cnt[u][0] : so con mau trang toi da trong cay con goc u ma u la mau trang : cnt[u][0]=1;
cnt[u][1] : so la trong cay con goc u ma dinh u den cnt[u][1] = so la cay con goc u
dp[u][0] += max(dp[v][0],dp[v][1])
dp[u][1] += max(dp[v][0],dp[v][1])
dp[u][0] += cnt[v][1]( dp[v][1] la max)
dp[u][0] += 1 (dp[v][0]) la max
dp[u][1] += cnt[v1][1]*cnt[v2][1](dp[v1][1]) 
*/
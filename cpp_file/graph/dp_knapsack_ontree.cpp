#include <bits/stdc++.h>
using namespace std;
// dp[u][x] gia tri lon nhat trong cay con goc u 
xet cac con v1,v2,...,vk voi so luong la h1,h2,...,hk
f[i][x] gia tri lon nhat duoc chon
chon f[i+1][x+h[i+1]] = f[i][x] + dp[v[i+1]][h[i+1]]
ko chon f[i+1][x] = f[i][x];
dp[u][x] = max(dp[u][x],dp[n][x]);
int main(){
	
}

/*
tài nguyên : có C ngày , danh sách n máy in máy thứ i chỉ được bán vào ngày Di với giá ri mua máy với giá ri nếu dùng để in thì mất g[i]
mục tiêu : sau D ngày phải tối ưu số tiền kiếm được 
các thao tác có thể thực hiện : 
	+bán ()
	+ mua ()
	+ in tiền ()
	dp[i]=max(dp[j]+r[j]+(d[i]-d[j]-1)*g[j]-p[i]) 	= max( g[j]*d[i]-g[j]*(d[j]+1)+dp[j]+r[j])-p[i]
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	 
}
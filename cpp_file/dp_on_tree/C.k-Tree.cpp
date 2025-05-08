// Đề bài: cho một cây vô hạn gọi là cây đầy đủ bậc k (mỗi nút có đúng k nút con) nút con thứ i của đỉnh bất kỳ có trọng số là i
// đếm số số đường đi đến gốc có trọng số là n và có ít nhất 1 cạnh có trọng số lớn hơn d
// dp[x][1] số đường đi có tổng bằng x đã có 1 cạnh lớn hoặc bằng d --------> ds=dp[n][1]
// dp[x][1] số đường đi có tổng bằng x chưa có có 1 cạnh lớn hoặc bằng d
// dp[x][1] = S(dp[x-i][0]) [d<=i<=k] + S(dp[x-i][1]) [1<=i<=k]
// dp[x][0] = S(dp[x-i][0]) [1<=i<d]
#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;


typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int n,d,k;
ll dp[maxn][2];
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k>>d;
    dp[0][0]=1;
    rei(x,1,n){
        rei(i,1,k){
            if(x>=i) dp[x][1]=(dp[x][1]+dp[x-i][1])%mod;
        }
        rei(i,d,k){
            if(x>=i) dp[x][1]=(dp[x][1]+dp[x-i][0])%mod;
        }
        rei(i,1,d-1){
            if(x>=i) dp[x][0]=(dp[x][0]+dp[x-i][0])%mod;
        }
    }
    cout<<dp[n][1];
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
} 
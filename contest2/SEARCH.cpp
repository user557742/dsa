#include <bits/stdc++.h>
using namespace std;
int n,m;
const int maxn = 201;

string cong(string a,string b){
	if(a=="0"&&b=="0") return "0";
	while(a.size()<b.size()) a='0'+a;
	while(b.size()<a.size()) b='0'+b;
	string res="";
	int nho=0;
	for(int i=a.size()-1;i>=0;i--){
		int tong=(a[i]-'0')+(b[i]-'0')+nho;
		if(tong>9){
			tong=tong%10;
			nho=1;
		}else nho=0;
		res=char(tong+'0')+res;
	}
	if(nho>0) res=char(1+'0')+res;
	return res;
}
string dp[maxn][maxn][maxn][2];
#define rei(i,a,b) for(int i=a;i<=b;i++)
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("SEARCH.INP","r")){
        freopen("SEARCH.INP","r",stdin);
        freopen("SEARCH.OUT","w",stdout);
    }
    cin>>n>>m;
    if(n==m){
        cout<<0;
        return 0;
    }
    rei(i,1,m) dp[i][1][i][(m-i)%2]="1";
    rei(i,1,m-1){
        rei(j,1,n){
            rei(k,1,m){
                rei(x,0,1){
                    dp[i+1][j][i][x]=cong(dp[i+1][j][i][x],dp[i][j][k][x]);
                    if(j<n) dp[i+1][j+1][i+1][(x+i+1-k-1)%2]=cong(dp[i+1][j+1][i+1][(x+i+1-k-1)%2],dp[i][j][k][x]);
                }
            }
        }
    }
    string ds="0";
    rei(k,n,m) ds=cong(ds,dp[m][n][k][1]);
    
    cout<<ds;
}
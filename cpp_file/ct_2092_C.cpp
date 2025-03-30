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
int n;
int a[maxn];
void solve(){
    int ch=0,le=0;
    ll s=0;
    int gg=0;
    rei(i,1,n){
        s+=a[i];gg=max(gg,a[i]);
        if(a[i]%2==0) ch++;
        else le++;
    }
    if(ch==0||le==0){
        cout<<gg<<"\n";
        return;
    }
    cout<<s-le+1<<"\n";
    /// NX : lúc nào cũng chỉ có một số lượng không đổi số lẻ 
    // chọn một số lẻ làm nơi chứa 
    // số chẵn ----> số lẻ ------> nơi chứa 
    // số chẵn -> 0 . số lẻ vẫn nguyên 
    // từ đó ta sẽ loại bỏ mọi số chẵn
    // gt nc + = tổng số chẵn
    // với mỗi số lẻ ta hi sinh 1 đv để có số chẵn tiếp tục quá trình khử chẵn như trên ta được 1 mảng có 1 số 1 1 1 1 ... x x là giá trị của nơi chứa
    // gt nc= tổng số lẻ - số số lẻ +1
}

int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        cin>>n;
        rei(i,1,n) cin>>a[i];
        solve();
    }


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
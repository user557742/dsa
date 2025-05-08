// bo bai co n la 
// A cam mot so la 
// B cam so la con lai
// lá i thắng j khi i>j ngoại lệ (1 thắng n)
// ai đến lượt mà hết bài thì thua --> lấy nhiều bài nhất có thể 
// A đánh trước B đánh sau
// A chọn 1 lá bài đặt lên bàn B cũng làm như thể ngay sau A 
// nếu con của A nhỏ hơn thì A mất bài B được của A
// và ngược lại
// tìm người thắng nếu cả 2 đều chơi tối ưu
/*
    Tư tưởng luôn lấy ra con to nhất trong tập bài
    Th1: ai mà có cả 1 và n thì người ấy thắng luôn 
    Th2: mỗi người đều chỉ có 1 hoặc n
        + nếu là bob có n và có ít nhất 2 lá thì anh ta luôn thắng
        + nêu alice có n thì nếu cô ta có lá bài khác nhỏ hơn n mà lớn hơn tất cả lá bài của Bob thì Alice thắng
*/
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
string inp;
void solve(){
    cin>>n;
    cin>>inp;
    inp=" "+inp;
    vector<int> a,b;
    rei(i,1,n){
        if(inp[i]=='A') a.push_back(i);
        else b.push_back(i);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    bool aco1=0,acon=0;
    bool bco1=0,bcon=0;
    for(int x:a){
        if(x==1) aco1=1;
        if(x==n) acon=1;
    }
    for(int y:b){
        if(y==1) bco1=1;
        if(y==n) bcon=1;
    }
    if(aco1+acon==2){
        cout<<"Alice\n";
        return ;
    }
    if(bco1+bcon==2){
        cout<<"Bob\n";
        return ;
    }
    if(bcon){
        if(b.size()>1) cout<<"Bob\n";
        else cout<<"Alice\n";
    }
    else {
        if(a[a.size()-1]==n){
            if(a.size()<2) cout<<"Bob\n";
            else if(a[a.size()-2]>b[b.size()-1]) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        
    }
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
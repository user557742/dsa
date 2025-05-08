// Đề bài : dãy lý tưởng là đãy mà mọi phần tử đề lớn hơn 2 và mọi i,j ta luôn có gcd(a[i],a[j])=1 
// ta có những thao tác sau
//  lấy một đơn vị từ một số bất kỳ
//  nếu có một đơn vị nào đã bị lấy ra ta có thể thêm vào một phần tử nào đó
/*
    ta có thể sử dụng thao tác để biến dãy cho trước thành mảng lý tưởng thì dãy đó có thể coi là đẹp
    tìm cách loại bỏ ít phần tử nhất để đãy trở thành đẹp
*/
// tư tưởng : đễ thấy một dãy toàn các số nguyên tố thì là một dãy lý tưởng
//nx: nếu dãy có độ dài k là đẹp thì ta có thể biến thành dãy có toàn các số nguyên tố đầu tiên có độ dài k
// ví dụ 1 3 5 8 có thể biến thành 2 3 5 7
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
int e[maxn];
int snt[maxn];
int n;
int a[maxn];
ll s[maxn];
ll p[maxn];
bool cmp(int u,int v){
    return u>v;
}
bool f(int k){
    return s[k]>=snt[k];
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=2;i*i<maxn;i++) if(e[i]==i) for(int j=i;j<maxn;j+=i) e[j]=i;
    int m=0;
    rei(i,2,maxn-1) if(e[i]==i){
        m++;
        snt[m]=i;
    }
    rei(i,1,m) p[i]=p[i-1]+snt[i];
    int t;cin>>t;
    while(t--){
        cin>>n;
        rei(i,1,n) cin>>a[i];
        rei(i,2,maxn-1) e[i]=i;
        
        sort(a+1,a+n+1,cmp);
        rei(i,1,n)s[i]=s[i-1]+a[i];
        int lo=1,hi=n;
        while(lo+1<hi){
            int mid=(lo+hi)/2;
            if(f(mid)) lo=mid;
            else hi=mid;
        }
        cout<<n-lo<<"\n";
    }
    
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
// cho cây n đỉnh . đỉnh thứ i có giá trị là p[i] với mỗi u đếm số lượng con cháu v mà p[v]>p[u] 
//n<=10^5
// chuyen cay thanh mang 
// truy van : đếm số điểm lớn hơn x trong đoạn [l ,r] trên đoạn (khong thể o(n^2)) 
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
vector<int> adj[maxn];
int id=0;
int pos[maxn];
int bd[maxn],kt[maxn];
void dfs(int u,int dad){
    id++;
    bd[u]=id;
    pos[id]=u;
    for(int v:adj[u]) if(v!=dad){
        dfs(v,u);
    }
    kt[u]=id;
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n-1){
        int j;cin>>j;
        adj[i].pb(j);
        adj[j].pb(i);
    } 
    dfs(1,0);
    rei(i,1,n){
        ll ds=0;
        rei(j,bd[i]+1,kt[i]){
            if(a[pos[j]]>a[i]) ds++;
        }
        cout<<ds<<"\n";
    }
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
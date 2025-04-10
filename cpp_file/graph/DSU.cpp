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
struct DSU{
    vector<int> sz;
    vector<int> pre;
    void init(int n){
        sz.resize(n+1,0);
        pre.resize(n+1,0);
    }
    void makeset(int a){
        pre[a]=a;
        sz[a]=1;
    }
    void find(int a){
        return (a!=pre[a]) ? v : pre[v]=find(pre[v]);
    }
    void uni(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(sz[a]<sz[b]) swap(a,b);
            pre[b]=a;
            sz[b]+=sz[b];
        }

    }
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
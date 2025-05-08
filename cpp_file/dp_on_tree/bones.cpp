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
int s1,s2,s3;
map<int,int> m;
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>s1>>s2>>s3;
    rei(i,1,s1){
        rei(j,1,s2){
            rei(k,1,s3){
                m[i+j+k]++;
            }
        }
    }
    int tmp=0;
    int ds=0;
    for(pair<int,int> x:m){
        if(x.second==tmp){
            if(ds>x.first) ds=x.first;
        }
        if(x.second>tmp){
            tmp=x.second;
            ds=x.first;
        }
    }
    cout<<ds;
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
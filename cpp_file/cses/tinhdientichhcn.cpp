#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
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
struct hcn{
    int x1,y1,x2,y2;
};
hnc a[1001];
struct line{
    int y,x1,x2;
};
bool operator < (line u,line v){
    if(u.y==v.y) return {u.x1,u.x2}<{v.x1,v.x2};
    return u.y<v.y;
}
void input(){
    cin>>n;
    rei(i,1,n) cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
}
pair<line,bool> X[2*maxn];
void taphop(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        line g1,g2;
        g1.y=a[i].y1;g1.x1=a[i].x1;g1.x2=a[i].x2;
        g2.y=a[i].y2;g2.x1=a[i].x1;g2.x2=a[i].x2;
        cnt++;
        X[cnt]={g1,1};
        cnt++;
        X[cnt]={g2,0};
    }
}
vector<int>
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    


    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
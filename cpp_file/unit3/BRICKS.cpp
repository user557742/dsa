// hinh vuong co duong cheo a 
// nx : a luon chan 
// neu toa do x , y co dang 
// x=h*a va y=k*a+a/2
// hoac x=u*a+a/2 va y=v*a
// thi la dat a=2t 
// neu x chia het cho a va y chia het cho a va y/a le --> a tm
// va nguoc lai
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
int solve(int x,int y){
    int lim=max(x,y);
    int ds=0;
    for(int a=2;a<=lim;a+=2){
        cout<<a<<" ";
        if(x%a==0){
            int tmpa=a/2;
            if(y%tmpa==0){
                if((y/tmpa)%2!=0){
                    ds++;
                    continue; 
                }
            }
        }
        else{
            int tmpa=a/2;
            if(x%tmpa==0){
                if((x/tmpa)%2!=0){
                    ds++;
                    continue;
                }
            }
        }
    }
    return ds;
}
int n;
pair<int,int> p[maxn];
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    rei(i,1,n) cin>>p[i].X>>p[i].Y;
    rei(i,1,n){
        cout<<solve(p[i].X,p[i].Y)<<"\n";
    }

    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
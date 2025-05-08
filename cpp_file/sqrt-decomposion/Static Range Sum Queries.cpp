// để luyện chia căn 
// với mảng n ta chia thành √n 
// tính trước rồi truy vấn
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
ll a[maxn];
ll bl[maxn];
int getbl(int x,int blsz){
    return x/blsz;
}
ll getans(int l,int r,int blsz){
    ll ds=0;
    int u=getbl(l,blsz);
    int v=getbl(r,blsz);
    if(u==v){
        for(int i=l;i<=r;i++) ds+=a[i];
        return ds;
    }
    rei(i,u+1,v-1) ds+=bl[i];
    rei(i,l,blsz*(u+1)-1) ds+=a[i];
    rei(i,blsz*v,r) ds+=a[i];
    return ds;
}
void upd(int k,int x,int blsz){
    int u=getbl(k,blsz);
    bl[u]=bl[u]-a[k]+x;
    a[k]=x;
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>n>>q;
    rei(i,1,n){
        cin>>a[i];
    }int blsz=sqrt(n);
    rei(i,1,n){
        bl[getbl(i,blsz)]+=a[i];
    }
    while(q--){
        int l;cin>>l;
        if(l==1){
            int k,x;cin>>k>>x;
            upd(k,x,blsz);
        }
        else{
            int u,v;cin>>u>>v;
            cout<<getans(u,v,blsz)<<"\n";
        }
    }
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
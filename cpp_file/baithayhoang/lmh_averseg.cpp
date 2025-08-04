#include<bits/stdc++.h>
using namespace std;
int t,a,b,c;
typedef long long ll;
ll f(int L){
    int k=L/2;
    ll s1=1ll*(k+1)*a+1ll*k*b-1ll*L*c;
    ll s2=1ll*(k+1)*b+1ll*k*a-1ll*L*c;
    return min(abs(s1),abs(s2));
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        if(a+b==2*c){
            cout<<2<<"\n";
            continue;
        }
        ll bn=min(abs(a-c),abs(b-c));
        int bl=1;
        ll bd=1;
        ll e2=abs(a+b-2*c);
        if(e2*bd<bn*2||(e2*bd==bn*2&&2<bl)){
            bn=e2;
            bl=2;
            bd=2;
        }
        int dl=abs(a-b);
        int X=abs(2*c-a-b);
        int t0=X?dl/X:1;
        if(t0<1)t0=1;
        for(int d=-2;d<=2;d++){
            int L=t0+d;
            if(L>=3&&(L&1)){
                ll e=f(L);
                if(e*bd<bn*L||(e*bd==bn*L&&L<bl)){
                    bn=e;
                    bl=L;
                    bd=L;
                }
            }
        }
        cout<<bl<<"\n";
    }
    return 0;
}

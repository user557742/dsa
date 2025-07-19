#include <bits/stdc++.h>
using namespace std;
const int maxn =1e5+1;
int n,w,h;
double a[maxn],b[maxn];
pair<int,int> p[maxn];
bool f(double x){
    double lw=w,lh=h;
    double tongh=0;
    double maxd=0;
    double dong=0;
    for(int i=1;i<=n;i++){
        double na=a[i]*x;
        double nb=b[i]*x;
        if(na>lw||nb>lh) return 0;
        if(dong+na>lw){
            tongh+=maxd;
            dong=na;
            maxd=nb;
        }
        else {
            dong+=na;
            maxd=max(maxd,nb);
        }
    }
    tongh+=maxd;
    return tongh<=lh;
}
const double e=1e-4;
void bs(){
    double lo=0,hi=1;
    while(f(hi)){
        lo=hi;
        hi*=2;
    }
    while(lo+e<hi){
        double mid=(lo+hi)/2;
        if(f(mid)) lo=mid;
        else hi=mid;
        //cout<<lo<<" "<<hi<<"\n";
    }
    cout<<fixed;
    cout.precision(4);
    cout<<lo;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>w>>h;
    for(int i=1;i<=n;i++) cin>>p[i].first>>p[i].second;
    //sort(p+1,p+n+1);
    for(int i=1;i<=n;i++){
        a[i]=p[i].first;
        b[i]=p[i].second;
    }

    bs();
}

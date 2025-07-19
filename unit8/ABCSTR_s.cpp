
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int n;
string s;
int sa[maxn],sb[maxn],sc[maxn];
void sub1(){
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1];
        sb[i]=sb[i-1];
        sc[i]=sc[i-1];
        if(s[i]=='A') sa[i]++;
        if(s[i]=='B') sb[i]++;
        if(s[i]=='C') sc[i]++;
    }
    int ds=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(sa[j]-sa[i-1]==sb[j]-sb[i-1]&&sb[j]-sb[i-1]==sc[j]-sc[i-1]) ds++;
        }
    }
    cout<<ds;
}
int main(){
    if(fopen("ABCSTR.INP","r")){
        freopen("ABCSTR.INP","r",stdin);
        freopen("ABCSTR.ANS","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.size();
    s=" "+s;
    sub1();
}

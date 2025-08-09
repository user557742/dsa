#include <bits/stdc++.h>
using namespace std;
const int maxn =1e5+1;
char a[maxn];
int s[maxn][3];
int main(){
    if(fopen("hps.in","r")){
        freopen("hps.in","r",stdin);
        freopen("hps.out","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        for(int j=0;j<3;j++) s[i][j]=s[i-1][j];
        if(a[i]=='S') s[i][0]++;
        if(a[i]=='P') s[i][2]++;
        if(a[i]=='H') s[i][1]++;
    }
    int ds=0;
    for(int i=1;i<=n;i++){
        for(int u=0;u<3;u++){
            for(int v=0;v<3;v++){
                ds=max(ds,s[i][u]+s[n][v]-s[i][v]);
            }
        }
    }
    cout<<ds;
    return 0;
}

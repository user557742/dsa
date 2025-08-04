#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5+1;
const int maxv = 101;
typedef long long ll;
int x[maxn],y[maxn],z[maxn];
ll cx[maxv],cy[maxv],cz[maxv];
ll cxy[maxv][maxv],cyz[maxv][maxv],czx[maxv][maxv];
ll cxyz[maxv][maxv][maxv];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i]>>z[i];
    long long ds=0;
    for(int i=1;i<=n;i++){
        cx[x[i]]++;cy[y[i]]++;cz[z[i]]++;
        cxy[x[i]][y[i]]++;cyz[y[i]][z[i]]++;czx[z[i]][x[i]]++;
        cxyz[x[i]][y[i]][z[i]]++;
        ds+=cx[x[i]]+cy[y[i]]+cz[z[i]]-2*(cxy[x[i]][y[i]]+cyz[y[i]][z[i]]+czx[z[i]][x[i]])+3*cxyz[x[i]][y[i]][z[i]];

    }
    cout<<ds;
    return 0;
}

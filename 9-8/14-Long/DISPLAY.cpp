#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,k;
const int  maxn = 1e3+1;
int x[maxn][maxn];
void upd(int i,int j){
    for(int u=i;u<=i+a-1;u++){
        for(int v=j;v<=j+b-1;v++){
            x[i][j]=(x[i][j]+1)%k;
        }
    }
}
int main(){
    if(fopen("DISPLAY.INP","r")){
        freopen("DISPLAY.INP","r",stdin);
        freopen("DISPLAY.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>a>>b;
    cin>>k;
    int ds=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>x[i][j];
    cout<<"IMPOSSIBLE";
}

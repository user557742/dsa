#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 444;
int a[maxn][maxn];
int cnt[16];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    while(n--){
        int u,v,c;
        cin>>u>>v>>c;
        a[u+200][v+200]=c;
    }
    long long ds=0;
    for(int l=0;l<=400;l++){
        for(int r=l+1;r<=400;r++){
            memset(cnt,0,sizeof(cnt));
            for(int h=0;h<=400;h++){
                if(a[h][l]==0||a[h][r]==0||(a[h][l]==a[h][r])) continue;
                int x=0;
                x=x|(1<<(a[h][l]-1));
                x=x|(1<<(a[h][r]-1));
                ds+=cnt[15-x];
                cnt[x]++;
            }
        }
    }
    cout<<ds;
}

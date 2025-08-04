/*
do khong luu duoc so am nen
    bat dau tu so(0,-m,m)
    (q,s,r) --> (q+1,r,s-1)
    (q,s,r) --> (q-1,r+1,s)
    (q,s,r) --> (q,r-1,s+1)
    phai den (x,y,z)  
*/
/*
de tranh luu so am ta cong m vao
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e2+1;
int a[maxn][maxn][maxn];
int n,m;
int _q[3]={1,-1,0};
int _s[3]={0,1,-1};
int _r[3]={-1,0,1};
int d[maxn][maxn][maxn];
struct o{
    int u,s,r;
    o(int tu=0,int ts=0,int tr=0) : u(tu),s(ts),r(tr) {}
};
bool operator < (o u,o v){
    return u.u<v.u;
}
void bfs(int sq,int ss,int sr){
    for(int i=0;i<=2*m;i++) for(int j=0;j<=2*m;j++) for(int k=0;k<=2*m;k++) d[i][j][k]=-1e9;
    queue <pair<int,o>> q;
    q.push({0,o(sq,ss,sr)});
    d[sq][ss][sr]=0;
    while(!q.empty()){
        int x=q.front().second.u;
        int y=q.front().second.s;
        int z=q.front().second.r;
        
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>m;
    n=1+3*m*(m+1);
    while(n--){
        int q,s,r,x;
        cin>>q>>s>>r>>x;
        q+=m;s+=m;r+=m;
        a[q][s][r]=x;
    }
    int x,y,z;cin>>x>>y>>z;
    return 0;
}
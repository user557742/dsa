#include <bits/stdc++.h>
using namespace std;
int r,c,k;
int a[505][505];
int b[505][505];
bool v[505][505];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool in(int x,int y){return x>=0&&x<r&&y>=0&&y<c;}
bool rf(int si,int sj,int D){
    memset(v,0,sizeof(v));
    queue<pair<int,int>>q;
    q.push({si,sj});
    v[si][sj]=1;
    int cnt=0;
    while(!q.empty()){
        auto p=q.front();q.pop();
        int x=p.first,y=p.second;
        ++cnt;
        if(cnt>=k) return true;
        for(int i=0;i<4;++i){
            int nx=x+dx[i], ny=y+dy[i];
            if(in(nx,ny) && !v[nx][ny] && abs(a[nx][ny]-a[x][y])<=D){
                v[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    return cnt>=k;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen("SKILEVEL.INP","r")){
        freopen("SKILEVEL.INP","r",stdin);
        freopen("SKILEVEL.OUT","w",stdout);
    }
    if(!(cin>>r>>c>>k)) return 0;
    int mx=INT_MIN,mn=INT_MAX;
    for(int i=0;i<r;++i) for(int j=0;j<c;++j){ cin>>a[i][j]; mx=max(mx,a[i][j]); mn=min(mn,a[i][j]); }
    vector<pair<int,int>> ss;
    for(int i=0;i<r;++i) for(int j=0;j<c;++j){ cin>>b[i][j]; if(b[i][j]) ss.push_back({i,j}); }
    int md = mx-mn;
    long long tot=0;
    for(auto &p: ss){
        int si=p.first, sj=p.second;
        if(k<=1){ tot+=0; continue; }
        int lo=0, hi=md;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(rf(si,sj,mid)) hi=mid; else lo=mid+1;
        }
        tot+=lo;
    }
    cout<<tot<<"\n";
    return 0;
}

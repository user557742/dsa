#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
struct F2 {
    int n,m;
    vector<vector<int>> a;
    F2(int _n,int _m):n(_n),m(_m),a(n+1,vector<int>(m+1,0)){}
    void u(int x,int y){
        for(int i=x;i<=n;i+=i&-i)
            for(int j=y;j<=m;j+=j&-j)
                a[i][j]++;
    }
    int q(int x,int y){
        int s=0;
        for(int i=x;i>0;i-=i&-i)
            for(int j=y;j>0;j-=j&-j)
                s+=a[i][j];
        return s;
    }
    int rq(int x1,int y1,int x2,int y2){
        if(x1>x2||y1>y2) return 0;
        return q(x2,y2)-q(x1-1,y2)-q(x2,y1-1)+q(x1-1,y1-1);
    }
};
int main(){
    if(fopen("SHAPECOM.INP","r")){
        freopen("SHAPECOM.INP","r",stdin);
        freopen("SHAPECOM.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int W,H,N,C;
    cin>>W>>H>>N>>C;
    vector<pair<int,int>> P(N);
    vector<int> vs,vd;
    for(int i=0,x,y;i<N;i++){
        cin>>x>>y;
        int s=x+y, d=x-y;
        P[i]={s,d};
        vs.pb(s);
        vd.pb(d);
    }
    for(auto &p:P){
        vs.pb(p.X-C);
        vs.pb(p.X+C);
        vd.pb(p.Y-C);
        vd.pb(p.Y+C);
    }
    sort(vs.begin(),vs.end());
    vs.erase(unique(vs.begin(),vs.end()),vs.end());
    sort(vd.begin(),vd.end());
    vd.erase(unique(vd.begin(),vd.end()),vd.end());
    auto gS=[&](int v){return int(lb(vs.begin(),vs.end(),v)-vs.begin())+1;};
    auto gD=[&](int v){return int(lb(vd.begin(),vd.end(),v)-vd.begin())+1;};
    F2 fw(vs.size(),vd.size());
    for(auto &p:P) fw.u(gS(p.X), gD(p.Y));
    int ans=N+1, ax=0, ay=0;
    for(int S=C;S<=W+H-C;S++){
        for(int D=-H+C;D<=W-C;D++){
            if(((S-D)&1)) continue;
            int x=(S+D)/2, y=(S-D)/2;
            if(x<C||x>W-C||y<C||y>H-C) continue;
            int s1=gS(S-C), s2=gS(S+C);
            int d1=gD(D-C), d2=gD(D+C);
            int c=fw.rq(s1,d1,s2,d2);
            if(c<ans){
                ans=c; ax=x; ay=y;
            }
        }
    }
    cout<<ans<<"\n"<<ax<<" "<<ay<<"\n";
    return 0;
}

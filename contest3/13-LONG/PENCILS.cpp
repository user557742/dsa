#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n,k;
struct c{
    int r=0,g=0,b=0;
    c(int _r=0,int _g=0,int _b=0) : r(_r),g(_g),b(_b) {}
} a[maxn];  
bool cmp1(c u,c v){
    if(u.r==v.r) return make_pair(u.g,u.b)<make_pair(v.g,v.b);
    return u.r<v.r;
}
bool cmp2(c u,c v){
    if(u.g==v.g) return make_pair(u.r,u.b)<make_pair(v.r,v.b);
    return u.g<v.g;
}
bool cmp3(c u,c v){
    if(u.b==v.b) return make_pair(u.r,u.g)<make_pair(v.r,v.g);
    return u.b<v.b;
}
int strmax[20][maxn];
int stgmax[20][maxn];
int stbmax[20][maxn];
int strmin[20][maxn];
int stgmin[20][maxn];
int stbmin[20][maxn];
void build(){
    memset(strmin,0,sizeof(strmin));
    memset(stgmin,0,sizeof(stgmin));
    memset(stbmin,0,sizeof(stbmin));
    memset(strmax,0,sizeof(strmax));
    memset(stgmax,0,sizeof(stgmax));
    memset(stbmax,0,sizeof(stbmax));
    for(int i=1;i<=n;i++){
        strmin[0][i]=strmax[0][i]=a[i].r;
        stgmin[0][i]=stgmax[0][i]=a[i].g;
        stbmin[0][i]=stbmax[0][i]=a[i].b;
    }
    int k=__lg(n);
    for(int i=1;i<=k;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            strmin[i][j]=min(strmin[i-1][j],strmin[i-1][j+(1<<(i-1))]);
            stgmin[i][j]=min(stgmin[i-1][j],stgmin[i-1][j+(1<<(i-1))]);
            stbmin[i][j]=min(stbmin[i-1][j],stbmin[i-1][j+(1<<(i-1))]);
            strmax[i][j]=max(strmax[i-1][j],strmax[i-1][j+(1<<(i-1))]);
            stgmax[i][j]=max(stgmax[i-1][j],stgmax[i-1][j+(1<<(i-1))]);
            stbmax[i][j]=max(stbmax[i-1][j],stbmax[i-1][j+(1<<(i-1))]);
        }
    }
}
int gmaxr(int l,int r){
    int i=__lg(r-l+1);
    return max(strmax[i][l],strmax[i][r-(1<<i)+1]);
}
int gmaxg(int l,int r){
    int i=__lg(r-l+1);
    return max(stgmax[i][l],stgmax[i][r-(1<<i)+1]);
}
int gmaxb(int l,int r){
    int i=__lg(r-l+1);
    return max(stbmax[i][l],stbmax[i][r-(1<<i)+1]);
}
int gminr(int l,int r){
    int i=__lg(r-l+1);
    return min(strmin[i][l],strmin[i][r-(1<<i)+1]);
}
int gming(int l,int r){
    int i=__lg(r-l+1);
    return min(stgmin[i][l],stgmin[i][r-(1<<i)+1]);
}
int gminb(int l,int r){
    int i=__lg(r-l+1);
    return min(stbmin[i][l],stbmin[i][r-(1<<i)+1]);
}
int solve1(){
    sort(a+1,a+n+1,cmp1);
    build();
    int ds=1e9;
    for(int l=1;l<=n-k+1;l++){
        int r=l+k-1;
        int ans=max({gmaxr(l,r)-gminr(l,r),gmaxg(l,r)-gming(l,r),gmaxb(l,r)-gminb(l,r)});
        ds=min(ds,ans);
    }
    return ds;
}
int solve2(){
    sort(a+1,a+n+1,cmp2);
    build();
    int ds=1e9;
    for(int l=1;l<=n-k+1;l++){
        int r=l+k-1;
        int ans=max({gmaxr(l,r)-gminr(l,r),gmaxg(l,r)-gming(l,r),gmaxb(l,r)-gminb(l,r)});
        ds=min(ds,ans);
    }
    return ds;
}
int solve3(){
    sort(a+1,a+n+1,cmp3);
    build();
    int ds=1e9;
    for(int l=1;l<=n-k+1;l++){
        int r=l+k-1;
        int ans=max({gmaxr(l,r)-gminr(l,r),gmaxg(l,r)-gming(l,r),gmaxb(l,r)-gminb(l,r)});
        ds=min(ds,ans);
    }
    return ds;
}
int main(){
    if(fopen("PENCILS.INP","r")){
        freopen("PENCILS.INP","r",stdin);
        freopen("PENCILS.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i].r>>a[i].g>>a[i].b;
    cout<<min({solve1(),solve2(),solve3()});
}
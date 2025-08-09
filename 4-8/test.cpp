#include <bits/stdc++.h>
using namespace std;
const int maxm= 2e5+1;
int n,m;
typedef long long ll;
ll dp[maxm];
struct xe{
    int x1=0,y1=0,x2=0,y2=0;
    xe(int _x1=0,int _y1=0,int _x2=0,int _y2=0) : x1(_x1),y1(_y1),x2(_x2),y2(_y2) {}
} a[maxm];
ll cost(int i,int j){
    return abs(a[i].x1-a[j].x2)+abs(a[i].y1-a[j].y2);
}
void sub2(){
    for(int i=1;i<=m;i++){
        for(int j=1;j<i;j++) if (a[j].x2 <= a[i].x1 && a[j].y2 <= a[i].y1) dp[i] = min(dp[i], dp[j] + a[i].x1 - a[j].x2 + a[i].y1 - a[j].y2);

    }
    cout<<dp[m];
}
bool cmp(const xe &u, const xe &v){
  if (u.x1 != v.x1) return u.x1 < v.x1;
  return u.y1 < v.y1;
}

struct st{
    int s[4*maxm];
    void init(){
        for(int i=1;i<=4*m;i++) s[i]=1e9;
    }
    void upd(int k,int x,int r=1,int lo=1,int hi=2*m){
        if(lo==hi){
            s[r]=min(x,s[r]);
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid)upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=min(s[2*r],s[2*r+1]);
    }
    ll get(int u,int v,int r=1,int lo=1,int hi=2*m){
        if(u>hi||v<lo) return 1e9;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return min(get(u,v,2*r,lo,mid),get(u,v,2*r+1,mid+1,hi));
    }
}t;
int tmpy[maxm];
int gg(int y){
    return lower_bound(tmpy+1,tmpy+2*m+1,y)-tmpy;
}
void sub3(){
    t.init();
    int id=0;
    for(int i=1;i<=m;i++){
        tmpy[++id]=a[i].y1;
        tmpy[++id]=a[i].y2;
    }
    sort(tmpy+1,tmpy+2*m+1);
    for(int i=1;i<=m;i++){
        dp[i]=min(dp[i],t.get(1,gg(a[i].y1))+a[i].x1+a[i].y1);
        t.upd(gg(a[i].y2),dp[i]-a[i].x2-a[i].y2);
    }
    cout<<dp[m];
}
int main(){
    /*if(fopen("WALK.INP","r")){
        freopen("WALK.INP","r",stdin);
        freopen("WALK.OUT","w",stdout);
    }*/

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
    }
    a[++m]=xe(n,n,n,n);
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=m;i++) dp[i]=a[i].x1+a[i].y1;
    if(m<=5000) sub2();
    else sub3();
    return 0;
}


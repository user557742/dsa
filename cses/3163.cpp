#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int n,q;
int x[maxn];
struct que{
    int a=0,b=0,c=0,d=0;int id=0;
}tv[maxn];
int sz=0;
inline int gbl(int i){
    if(i%sz==0) return i/sz;
    return i/sz+1;
}
inline bool cmp(que u,que v){
    if(gbl(u.a)==gbl(v.a)){
        if(gbl(u.a)%2==0) return u.b<v.b;
        else return u.b>v.b;
    }
    return gbl(u.a)<gbl(v.a);
}
int id;
struct it{
    int s[maxn];
    void init(){
        for(int i=1;i<=id;i++) s[i]=0;
    }
    inline void upd(int i, int x) {
        for (; i <= id; i += i & -i)
            s[i] += x;
    }
    inline int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += s[i];
        return sum;
    }  
    inline int get(int u,int v){
        return query(v)-query(u-1);
    }
}t;
int ans[maxn];
int tmp[maxn];
int ds[maxn];
inline void add(int i){
    t.upd(x[i],1);
}
inline void del(int i){
    t.upd(x[i],-1);
}
inline int getans(int c,int d){
    
    return t.get(c,d);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)cin>>x[i];
    for(int i=1;i<=n;i++) tmp[id++]=x[i];
    for(int i=1;i<=q;i++){
        cin>>tv[i].a>>tv[i].b>>tv[i].c>>tv[i].d;
        tmp[id++]=tv[i].c;
        tmp[id++]=tv[i].d;
        tv[i].id=i;
    }
    sort(tmp+1,tmp+id+1);
    for(int i=1;i<=n;i++) x[i]=lower_bound(tmp+1,tmp+id+1,x[i])-tmp;
    sz=sqrt(n);
    for(int i=1;i<=q;i++){
        tv[i].c=lower_bound(tmp+1,tmp+id+1,tv[i].c)-tmp;
        tv[i].d=lower_bound(tmp+1,tmp+id+1,tv[i].d)-tmp;
    }
    t.init();
    sort(tv+1,tv+q+1,cmp);
    int cl=1,cr=0;
    for(int i=1;i<=q;i++){
        que g=tv[i];
        while(cl>g.a) add(--cl);
        while(cl<g.a) del(cl++);
        while(cr>g.b) del(cr--);
        while(cr<g.b) add(++cr);
        ans[g.id]=getans(g.c,g.d);
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,q;
const int maxn = 3e5+1;
int tmp[2*maxn];
const int maxnode = 6e6-1000;
struct node{
    int l=0,r=0,val=0;
    node(int _l=0,int _r=0,int _val=0) : l(_l),r(_r),val(_val) {}
};
struct pst{
    int root[maxn];
    node s[maxnode];
    int cnt=1;
    int build(int lo,int hi){
        int id=cnt++;
        if(lo==hi){
            s[id].val=0;
            return id;
        }
        int mid=(lo+hi)/2;
        s[id].l=build(lo,mid);
        s[id].r=build(mid+1,hi);
        s[id].val=s[s[id].l].val+s[s[id].r].val;
        return id;
    }
    int upd(int id,int k,int x,int lo,int hi){
        int nid=cnt++;
        s[nid]=s[id];
        if(lo==hi){
            s[nid].val+=x;
            return nid;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) s[nid].l=upd(s[id].l,k,x,lo,mid);
        else s[nid].r=upd(s[id].r,k,x,mid+1,hi);
        s[nid].val=s[s[nid].l].val+s[s[nid].r].val;
        return nid;
    }
    int get(int id,int u,int v,int lo,int hi){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[id].val;
        int mid=(lo+hi)/2;
        return get(s[id].l,u,v,lo,mid)+get(s[id].r,u,v,mid+1,hi);
    }
}t;
struct que{
    int a,b,c,d;
}tv[maxn];
int j=0;
int gg(int x){
    return lower_bound(tmp+1,tmp+j+1,x)-tmp;
}
int a[maxn];
int main(){
    if(fopen("in.txt","r")){
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) tmp[++j]=a[i];
    for(int i=1;i<=q;i++) cin>>tv[i].a>>tv[i].b>>tv[i].c>>tv[i].d;
    for(int i=1;i<=q;i++){
        int c=tv[i].c,d=tv[i].d;
        tmp[++j]=c;
        tmp[++j]=d;
    }
    sort(tmp+1,tmp+j+1);
    j = unique(tmp+1, tmp+j+1) - tmp - 1;
    t.root[0]=t.build(1,j);
    for(int i=1;i<=n;i++) t.root[i]=t.upd(t.root[i-1],gg(a[i]),1,1,j);
    for(int i=1;i<=q;i++){
        int a=tv[i].a,b=tv[i].b,c=tv[i].c,d=tv[i].d;
        int r=t.get(t.root[b],gg(c),gg(d),1,j);
        int l=t.get(t.root[a-1],gg(c),gg(d),1,j);
        cout<<r-l<<"\n";
    }
    return 0;
}

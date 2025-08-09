#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+1;
const int maxq = 2e5+1;
const int maxnode = (maxn+maxq)*20;
int n;
int a[maxn];
int q;
int tmp[maxn];
struct node{
    int val=0,l=0,r=0;
    node(int _val=0,int _l=0,int _r=0) : val(_val),l(_l),r(_r) {}
};
struct pst{
    int root[maxq];
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
int j=0;
int gg(int x){
    return lower_bound(tmp+1,tmp+j+1,x)-tmp;
}
struct que{
    int u,v,l;
}tv[maxq];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<=n;i++) tmp[++j]=a[i];
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>tv[i].u>>tv[i].v>>tv[i].l;
        tmp[++j]=tv[i].l;
    }
    sort(tmp+1,tmp+j+1);
    t.root[0]=t.build(1,j);
    for(int i=1;i<=n;i++) t.root[i]=t.upd(t.root[i-1],gg(a[i]),1,1,j);
    for(int i=1;i<=q;i++){
        int u=tv[i].u,v=tv[i].v;
        int r=t.get(t.root[v],gg(tv[i].l),j,1,j)-t.get(t.root[v],gg(tv[i].l),gg(tv[i].l),1,j);
        int l=t.get(t.root[u-1],gg(tv[i].l),j,1,j)-t.get(t.root[u-1],gg(tv[i].l),gg(tv[i].l),1,j);
        cout<<r-l<<"\n";
    }
    return 0;
}

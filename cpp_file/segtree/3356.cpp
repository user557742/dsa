#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
const int maxq = 1e5+1;
const int maxnode=4e6+1;
struct node{
    int val=0,sl=0,l=0,r=0;
};
struct pst{
    int root[maxn];
    node s[maxnode];
    int cnt=1;
    int build(int lo,int hi){
        int id=cnt++;
        if(lo==hi){
            s[id].val=0;
            s[id].sl=0;
            return id;
        }
        int mid=(lo+hi)/2;
        s[id].l=build(lo,mid);
        s[id].r=build(mid+1,hi);
        return id;
    }
    int upd(int id,int k,int x,int lo,int hi){
        int nid=cnt++;
        if(lo==hi){
            if(s[nid].sl==0){
                s[nid].val=1;
                s[nid].sl+=x;
            }
            else if(ss[nid].sl==1){
                if(x==-1){
                    ss[nid].sl+=x;
                    s[nid].val=0;
                }
            }else s[nid].sl+=x;
            return 0;
        }
        int mid=(lo+hi)/2;
        s[nid].l=t.upd(s[id].l,k,x,lo,mid);
        s[nid].r=t.upd(s[id].r,k,x,mid+1,hi);
        s[nid].val+=s[s[nid].l].val+s[s[nid].r].val;
    }
    int get(int id,int u,int v,int lo,int hi){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[id].val;
        int mid=(lo+hi)/2;
        return get(s[id].l,u,v,lo,mid)+get(s[id].r,u,v,mid+1,hi);
    }
}t;
int tmp[maxnode];
struct que{
    int l,u,v;
} tv[maxq];
int j=0;
int gg(int x){
    return lower_bound(tmp+1,tmp+j+1,x)-tmp;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) tmp[++j]=a[i];
    for(int i=1;i<=q;i++){
        cin>>tv[i].l>>tv[i].u>>tv[i].v;
        if(tv[i].l==1) tmp[++j]=tv[i].v;
    }
    sort(tmp+1,tmp+j+1);
    t.root[0]=t.build(1,j);
    int jk
    for(int i=1;i<=n;i++) t.root[i]=t.upd(t.root[i-1],gg(a[i]),1,1,j);

    for(int i=1;i<=n;i++){
        int l=tv[i].l,u=tv[i].u,v=tv[i].v;
        if(l==1){
            t.root[i]=t.upd(t.upd[i-1],a[u],-1,1,j);
            t.root[i]=t.upd(t.upd[])
        }
    }
    return 0;
}

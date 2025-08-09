#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
const int maxq = 2e5+1;
const int maxnode = 80e5+1;
int n,q;
int a[maxn];
struct node{
    int l=0,r=0,val=0;
    node(int _l=0,int _r=0,int _val=0) : l(_l),r(_r),val(_val) {}
};
int tmp[2*maxn];
struct pst{
    int root[maxq];
    node s[maxnode];
    int cnt=1;
    int build(int lo,int hi){
        int id=cnt++;
        if(lo==hi){
            s[id]=a[lo];
            return id;
        }
        int mid=(lo+hi)/2;
        s[id].l=build(lo,mid);
        s[id].r=build(mid+1,hi);
        s[id].val=s[s[id].l].val+s[s[id].r].val;
        return id;
    }
    int upd(int id,int k,int x,int lo,int hi){
        int nid=++cnt;
        s[nid]=s[id];
        if(lo==hi){
            s[nid].val+=x;
            return nid;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) s[nid].l=upd(s[id].l,lo,mid);
        else s[nid].r=upd(s[id].r,mid+1,hi);
        s[nid].val=s[s[nid].l].val+s[s[nid].r].val;
        return nid;
    }
    int get(int id,int u,int v,int lo,int hi){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[id].val;
        int mid=(lo+hi)/2;
        return get(s[id].l,u,v,lo,mid)+get(s[id].r,u,v,mid+1,hi);
    }
} t;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    t.root[0]=1;
    t.build(r);
    for(int i=1;i<=q;i++){
        int l;cin>>l;
        if(l==1){
            int u,x;cin>>u>>x;
            t.root[i]=t.upd(t.root[i-1],u,x,1,n)
        }
        else{
            int u,v;cin>>u>>v;
            root[i]=root[i-1];
            cout<<t.get(root[i],u,v,1,n)<<"\n";
        }
    }

    return 0;
}

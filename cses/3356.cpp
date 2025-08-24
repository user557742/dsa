#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
const int maxnode=maxn*40;
int n,q;
int a[maxn];
struct node{
    int val=0,cnt=0;
    int l=0,r=0;
    node(int _val=0,int _cnt=0,int _l=0,int _r=0):val(_val),cnt(_cnt),l(_l),r(_r) {}
};
struct pst{
    node s[maxnode];
    int root[2*maxn];
    int cnt=0;
    int build(int lo,int hi){
        int id=cnt++;
        if(lo==hi){
            s[id]=node(0,0);
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
            g[id].cnt+=x;
            if(g[i].cnt==1){
                g[i].val=0;
            }
            else g[i].val=1;
            return 0;
        }
        if(k<=mid) s[nid].l=upd(s[id].l,k,x,lo,mid);
        else s[nid].r=upd(s[id].r,k,x,mid+1,hi);
        s[nid].val+=s[s[nid].l].val+s[s[nid].r].val;
        return nid;
    }
    int get(int u,int v,int )
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    return 0;
}

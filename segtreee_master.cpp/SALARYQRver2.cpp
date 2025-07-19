#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e5+1;
int n,q;
int a[maxn];
char l[maxn];int u[maxn],v[maxn];
int tmp[2*maxn];
int m=1;
struct it{
    int s[4*maxn];
    void upd(int k,int x,int r=1,int lo=1,int hi=m){
        if(lo==hi){
            s[r]+=x;
            return ;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]+s[2*r+1];
    }
    int get(int u,int v,int r=1,int lo=1,int hi=m){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+hi)/2;
        return get(u,v,2*r,lo,mid)+get(u,v,2*r+1,mid+1,hi);
    }
}t;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        tmp[m]=a[i];
        m++;
    }
    for(int i=1;i<=q;i++){
        cin>>l[i]>>u[i]>>v[i];
        if(l[i]=='!'){
            tmp[m]=v[i];
            m++;
        }
        else{
            tmp[m]=u[i];
            m++;
            tmp[m]=v[i];
            m++;
        }
    }
    sort(tmp+1,tmp+m+1);
    for(int i=1;i<=n;i++){
        int g=lower_bound(tmp+1,tmp+m+1,a[i])-tmp;
        t.upd(g,1);
    }
    for(int i=1;i<=q;i++){
        if(l[i]=='!'){
            int g=lower_bound(tmp+1,tmp+m+1,a[u[i]])-tmp;
            t.upd(g,-1);
            int h=lower_bound(tmp+1,tmp+m+1,v[i])-tmp;
            t.upd(h,1);
            a[u[i]]=v[i];
        }
        else{
            int c=lower_bound(tmp+1,tmp+m+1,u[i])-tmp;
            int s=lower_bound(tmp+1,tmp+m+1,v[i])-tmp;
            cout<<t.get(c,s)<<"\n";
        }
    }
    
}
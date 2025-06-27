/*
bài toán cho 1 cây n đỉnh đỉnh i có giá trị a[i] và q truy vấn mỗi truy vấn có 2 loại 
    + loại 1 đặt k x : a[k]=x
    + loại 2 u  v : tính tổng xor trong đoạn [u,v]
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n,a[maxn],q;
vector<int> adj[maxn];
int depth[maxn],sz[maxn],heavy[maxn],head[maxn];
typedef long long ll;
struct it{
    ll s[4*maxn];
    void build(int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=a[lo];
            return ;
        }
        int mid=(lo+hi)/2;
        build(2*r,lo,mid);
        build(2*r+1,mid+1,hi);
        s[r]=s[2*r]^s[2*r+1];
    }  
    void upd(int k,int x,int r=1,int lo=1,int hi=n){
        if(lo==hi){
            s[r]=x;
            return ;
        }
        if(k<=mid) upd(k,x,2*r,lo,mid);
        else upd(k,x,2*r+1,mid+1,hi);
        s[r]=s[2*r]^s[2*r+1];
    }
    void get(int u,int v,int r=1,int lo=1,int hi=n){
        if(u>hi||lo>v) return 0;
        if(u<=lo&&hi<=v) return s[r];
        int mid=(lo+g=hi)/2;
        return get(u,v,2*r,lo,mid)^get(u,v,2*r+1,mid+1,hi);
    }
}t;
void dfs(int u,int dad){
    sz[u]=1;
    headv
}
void truyvan1(){

}
void truyvan2(){
    
}
int main(){
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>q;
    while(q--){
        int l;cin>>l;
        if(l==1) truyvan1();
        else truyvan2();
    }
}
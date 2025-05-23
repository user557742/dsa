#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 2e5+1;
#define rei(i,a,b) for(int i=a;i<=b;i++)
int n,q;
struct dsu{
    int pre[maxn],sz[maxn];
    void ms(int u){
        pre[u]=u;
        sz[u]=1;
    }
    int find(int u){
        if(u==pre[u]) return u;
        return pre[u]=find(pre[u]);
    }
    void join(int u,int v){
        u=find(u);
        v=find(v);
        if(v!=u){
            if(sz[u]<sz[v]) swap(u,v);
            sz[u]+=sz[v];pre[v]=u;
        }
    }
} ds;
bool vis[maxn];
vector<int> tmp;
void truyvan1(){
    int x,y;
    cin>>x>>y;
    ds.join(x,y);
    vis[x]=1;
    vis[y]=1;
}
void truyvan2(){
    int x,y;cin>>x>>y;
    /*int i=lower_bound(tmp.begin(),tmp.end(),x)-tmp.begin();
    int j=upper_bound(tmp.begin(),tmp.end(),x)-tmp.begin()-1;
    if(j-i+1<2) return ;*/
    rei(f,x,y-1) ds.join(f,f+1);
    //for(auto r=tmp.begin();r!=tmp.end();r++) if(vis[*r]) tmp.erase(r);
}
void truyvan3(){
    int x,y;cin>>x>>y;
    x=ds.find(x);
    y=ds.find(y);
    if(x==y) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    rei(i,1,n) tmp.push_back(i);
    rei(i,1,n) ds.ms(i);
    while(q--){
        int loai;cin>>loai;
        if(loai==1) truyvan1();
        if(loai==2) truyvan2();
        if(loai==3) truyvan3();
    }
}
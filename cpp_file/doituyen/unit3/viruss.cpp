#include<iostream>
#include <vector>
#define rei(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
using namespace std;
const int maxn= 1e5+1;
int n;
int id=0;
vector<int> adj[maxn];
int bd[maxn];
int kt[maxn],pos[maxn];
void dfs(int u,int dad){
    id++;
    bd[u]=id;pos[id]=u;
    for(int v:adj[u]) if(v!=dad) dfs(v,u);
    kt[u]=id;
}int ra,rb;
vector<int> adjb[maxn];
struct IT{
    int lz[4*maxn],s[4*maxn];
    int nho[4*maxn];
    void down(int r){
        if(nho[r]){
            lz[2*r]=lz[2*r+1]=lz[r];
            nho[2*r]=nho[2*r+1]=1;
            nho[r]=0;
        }
    }
    void up(int r,int lo,int hi){
        int mid=(lo+hi)/2;
        int L=(nho[2*r]) ? lz[2*r]*(mid-lo+1):s[2*r];
        int R=(nho[2*r+1]) ? lz[2*r+1]*(hi-mid) : s[2*r+1];
        s[r]=L+R;
    }
    void upd(int u,int v,int x,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return ;
        if(u<=lo&&hi<=v){
            lz[r]=x;
            nho[r]=1;
            return ;
        }
        int mid=(lo+hi)/2;
        down(r);
        upd(u,v,x,2*r,lo,mid);
        upd(u,v,x,2*r+1,mid+1,hi);
        up(r,lo,hi);
    }
    int get(int u,int v,int r=1,int lo=1,int hi=id){
        if(u>hi||v<lo) return 0;
        if(u<=lo&&hi<=v){
            return (nho[r]) ? lz[r]*(hi-lo+1) : s[r];
        }
        int mid=(lo+hi)/2;
        down(r);
        int L=get(u,v,2*r,lo,mid);
        int R=get(u,v,2*r+1,mid+1,hi);
        up(r,lo,hi);
        return L+R;
    }
}st;
int ds=0;
void dfsb(int u,int dad){
    ds+=st.get(bd[u],bd[u]);
    st.upd(bd[u]+1,kt[u],1);
    for(int v:adjb[u]) if(v!=dad){
        dfsb(v,u);
    }
    st.upd(bd[u]+1,kt[u],-1);
}
int main(){
    cin>>n;
    rei(i,1,n){
        int x;cin>>x;
        if(x==0) ra=i;
        else{
            adj[x].pb(i);
            adj[i].pb(x);
        }
    }
    rei(i,1,n){
        int x;cin>>x;
        if(x==0) rb=i;
        else{
            adjb[i].pb(x);
            adjb[x].pb(i);
        }
    }
    dfs(ra,0);
    dfsb(rb,0);
    cout<<ds;
}

// cho n canh dong moi canh dong co a[i] thoi diem cuoi cung ma co con xanh 
// trau muon di tu 1 den n lau nhat co the . khong bao gio di qua canh dong ua 
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+1;
int n;
int a[maxn];
vector<int> adj[maxn];
int vis[maxn];
bool f(int x){
    for(int i=1;i<=n;i++) vis[i]=0;
    queue<int> q;
    q.push(1);
    vis[1]=1;
    if(a[1]>x) return 0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            vis[v]=1;
            q.push(v);
        }
    }
    return vis[n];
}
int calc(){
    int lo=1e9,hi=0;
    for(int i=1;i<=n;i++){
        lo=min(lo,a[i]);
        hi=max(hi,a[i]);
    }/*
    if(f(hi)) return hi;
    while(lo+1<hi){
        int mid=(lo+hi)/2;
        if(f(mid)) lo=mid;
        else hi=hi;
    }
    return lo;*/
    for(int i=1;i<=10;i++) cout<<f(i)<<" ";
    cout<<"\n";
    return 0;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        if(i+1>n) adj[i].push_back(i+1);
        if(i+2>n) adj[i].push_back(i+2);
    }
    cout<<calc();
    return 0;
}

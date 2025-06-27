#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int base= 251;
typedef long long ll;
const int maxn = 1e6+1;
ll lt[maxn],gt[maxn];int n,m;
ll gethash(string x){
    ll ds=0;
    for(char c:x){
        ds=(ds*base+(c-'0'))%mod;
    }
    return ds;
}
void build(string x){
    lt[0]=1;
    for(int i=1;i<=(int)x.size();i++) lt[i]=(lt[i-1]*base)%mod;
    for(int i=1;i<=(int)x.size();i++) gt[i]=(gt[i-1]*base+(x[i-1]-'a'))%mod;
}
ll getans(int l,int r){
    ll tmp=(lt[r-l+1]*gt[l-1])%mod;
    return (gt[r]-tmp+mod)%mod;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    unordered_map<ll,int> mp;
    cin>>n>>m;
    string u;cin>>u;
    int l=n/m;
    for(int i=1;i<=m;i++){
        string s;cin>>s;
        mp[gethash(s)]=i;
        cout<<gethash(s)<<" ";
    }
    cout<<"\n";
    build(u);  
    for(int i=1;i<=n;i++) cout<<gt[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=m;i++){
        cout<<getans(i-l+1,i)<<" ";
    }
}

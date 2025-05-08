#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
const int base = 293;
using ll = long long;
typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
string conv(string s){
    string ds="";
    for(char x:s){
        if('A'<=x&&x<='Z') ds.pb(char(int(x)+32));
        else ds.pb(x);
    }
    return ds;
}
int n;
string a[maxn];
map<string,vector<string>> adj;
map<string,int> d;
void dfs(string u,string dad){
    for(string v:adj[u]) if(v!=dad){
        d[v]=d[u]+1;
        dfs(v,u);
    }
}
int main(){
    //clock_t ____st=clock();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    n=n+1;
    set<string> taphop;
    rei(i,1,n-1){
        string u,tmp,v;
        cin>>u>>tmp>>v;
        v=conv(v);
        u=conv(u);
        //cout<<v<<" "<<u<<"\n";
        taphop.insert(u);
        taphop.insert(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs("polycarp","null");
    int ds=0;
    for(string x:taphop) ds=max(ds,d[x]);
    cout<<ds+1;
    /*clock_t ____end=clock();
    cout<<"\nTime: "<<double(____end-____st)/CLOCKS_PER_SEC;*/
    return 0;
}
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define rei(i,a,b) for(int i=a;i<=b;i++)
const int maxn = 100001;
int n,c;
int a[maxn];
pair<int,int> p[maxn];
int main(){
    if(fopen("PAIRING.INP","r")){
        freopen("PAIRING.INP","r",stdin);
        freopen("PAIRING.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>c;
    rei(i,1,c) cin>>a[i];  
    set<pair<int,int>> s;
    rei(i,1,c) s.insert({a[i],i});
    while(s.size()){
        pair<int,int> mins=*s.begin();
        pair<int,int> maxs=*prev(s.end());
        s.erase(prev(s.end()));
        s.erase(s.begin());
        cout<<mins.second<<" "<<maxs.second<<"\n";
        mins.first--;
        maxs.first--;
        if(mins.first>0) s.insert(mins);
        if(maxs.first>0) s.insert(maxs);
    } 
}
#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    int n=s.size();
    s=" "+s;
    set<char> g;
    long long ds=0;
    for(int i=n;i>=1;i--){
        g.insert(s[i]);
        int cnt=0;
        for(char x:g) if(x!=s[i]&&s.size()>1) cnt++;
        ds+=cnt;
    }
    cout<<ds;
    return 0;
}

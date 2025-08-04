#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    long long d=1ll*n*(n+1);
    if(d%4==0){
        cout<<"YES\n";
        long long tg=d/4;
        vector<int> s1,s2;
        for(int i=n;i>=1;i--){
            if(tg>=i){
                tg-=i;
                s1.push_back(i);
            }
            else s2.push_back(i);
        }
        cout<<s1.size()<<"\n";
        for(int x:s1) cout<<x<<" ";
        cout<<"\n";
        cout<<s2.size()<<"\n";
        for(int x:s2) cout<<x<<" ";
    }
    else cout<<"NO\n";
    return 0;
} 
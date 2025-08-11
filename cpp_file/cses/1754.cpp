#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        long long a,b;cin>>a>>b;
        if((2*b-a)%3!=0){
            cout<<"NO\n";
            continue;
        }
        if((2*a-b)%3!=0){
            cout<<"NO\n";
            continue;
        }
        int x=(2*b-a)/3;
        int y=(2*a-b)/3;
        if(x>=0&&y>=0){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}

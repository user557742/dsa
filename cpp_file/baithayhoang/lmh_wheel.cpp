#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+3;
int n,m;
int a[maxn];
int b[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int cur=n-1;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>b[i];
        long long s=0;
        long long cnt=0;
        while(s<b[i]){
            s+=a[(cur+1)%n];
            cur=(cur+1)%n;
            cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

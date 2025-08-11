#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int n,m;
int a[maxn];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x;cin>>x;
        q1.push(x);
        q2.push(x);
    }
    int ds1=0,ds2=0;
    while(n--&&!q1.empty()&&!q2.empty()){
        int t1=q1.top();
        int t2=q2.top();
        //cout<<t2<<" ";
        q1.pop();q2.pop();
        ds1+=t1;
        ds2+=t2;
        if(t1>1) q1.push(t1-1);
        if(t2>1) q2.push(t2-1);
    }
    cout<<ds1<<" "<<ds2;
    return 0;
}

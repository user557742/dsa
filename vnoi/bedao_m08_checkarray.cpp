#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
     for (int i = 1;i <= n; ++i)
    {
        int x;
        cin>>x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 1;i < (int)a.size(); ++i)
        if (a[i] != a[i-1] + 1) return cout<<"NO" ,0;

    cout<<"YES";
    return 0;
}

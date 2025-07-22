#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1e5+1;
int n, g[maxn+10], a[maxn+10];
struct Pl { int c, h, id; } b[maxn+1];
bool cmpPl(const Pl &x, const Pl &y){
    return x.c > y.c;
}
int mm[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        cin >> b[i].h >> b[i].c;
        b[i].id = i;
    }
    multiset<pair<int,int>> ms;
    for(int i = 1; i <= n; i++){
        ms.insert({a[i], i});
    }
    sort(b+1, b+1+n, cmpPl);
    ll ds = 0;
    for(int i = 1; i <= n; i++){
        int h = b[i].h, c = b[i].c, id = b[i].id;
        auto it = ms.upper_bound({h, INT_MAX});
        if(it == ms.begin()) continue;
        --it;
        int fid = it->second;
        ds += c;
        g[fid] = id;
        ms.erase(it);
    }
    cout << ds << "\n";
    for(int i=1;i<=n;i++) mm[g[i]]=1;
    vector<int> thua;
    for(int i=1;i<=n;i++) if(mm[i]==0) thua.push_back(i);
    int id=0;
    for(int i=1;i<=n;i++){
        if(g[i]==0){
            cout<<thua[id]<<" ";
            id++;
        }
        else cout<<g[i]<<" ";
    }
    return 0;
}

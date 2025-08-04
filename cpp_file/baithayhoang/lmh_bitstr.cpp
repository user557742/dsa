#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+1;
int d[maxn];
const int inf= 1e9+1;
int d1[maxn];
int calca(const string &s, int m, char w) {
    int n=s.size();
    int cnt=0;
    for (int i=0,cur=0;i<n;i++) {
        cur += d[i];
        if (((s[i] - '0') ^ (cur & 1)) + '0' != w) {
            if (i + m > n) return inf;
            cnt++; cur++;
            d[i + m]--;
        }
    }
    return cnt;
}
int calcb(const string &s, int m, char w) {
    int n=s.size();
    int cnt=0;
    for (int i=0,cur=0;i<n;i++) {
        cur += d1[i];
        if (((s[i] - '0') ^ (cur & 1)) + '0' != w) {
            if (i + m > n) return inf;
            cnt++; cur++;
            d1[i + m]--;
        }
    }
    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; int m;
    cin >> s >> m;
    int r = min(calca(s, m, '0'), calcb(s, m, '1'));
    cout << (r == inf ? -1 : r);
    return 0;
}

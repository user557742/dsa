#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    map<char, char> m = {{')','('}, {']','['}, {'}','{'}, {'>','<'}};
    stack<pair<char,int>> st;
    int res = 0, last = -1;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (m.count(c)) {
            if (!st.empty() && st.top().first == m[c]) {
                st.pop();
                int len = st.empty() ? i - last : i - st.top().second;
                res = max(res, len);
            } else {
                while (!st.empty()) st.pop();
                last = i;
            }
        } else if (c == '(' || c == '[' || c == '{' || c == '<') {
            st.push({c, i});
        }
    }

    cout << res << '\n';
    return 0;
}


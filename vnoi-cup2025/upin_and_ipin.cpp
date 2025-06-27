#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<pair<ll,int>> pttsnt(ll x) {
    vector<pair<ll,int>> res;
    for (ll p = 2; p * p <= x; ++p) {
        if (x % p == 0) {
            int cnt = 0;
            while (x % p == 0) {
                x /= p;
                cnt++;
            }
            res.push_back({p, cnt});
        }
    }
    if (x > 1) {
        res.push_back({x, 1});
    }
    return res;
}
void dfs(int idx,ll cv,ll x,ll m,int d,const vector<ll>& pri,const vector<int>& am,const vector<int>& ex,unordered_map<ll, pair<ll,ll>>& dad,unordered_map<ll,int>& dist,queue<ll>& q,bool& cokq) {
    if (cokq) return;
    int sz = (int)pri.size();
    if (idx == sz) {
        if (cv == 1) return;
        ll nx = x * cv;
        if (nx > m) return;
        if (!dad.count(nx)) {
            dad[nx] = {x, cv};
            dist[nx] = d + 1;
            if (nx == m) {
                cokq = true;
                return;
            }
            q.push(nx);
        }
        return;
    }
    int maxE = min(ex[idx], am[idx] - ex[idx]);
    ll mul = 1;
    for (int e = 0; e <= maxE; ++e) {
        dfs(idx + 1, cv * mul, x, m, d, pri, am, ex, dad, dist, q, cokq);
        if (cokq) return;
        mul *= pri[idx];
    }
}

int main() {
    ios::sync_with_stdio(00);cin.tie(0);cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        if (n == m) {
            cout << 0 << "\n";
            continue;
        }
        if (n > m || m % n != 0) {
            cout << -1 << "\n";
            continue;
        }
        auto fn = pttsnt(n);
        auto fm = pttsnt(m);
        unordered_map<ll,int> mpfm;
        for (auto &pr : fm) {
            mpfm[pr.first] = pr.second;
        }
        bool ok = true;
        for (auto &pr : fn) {
            if (!mpfm.count(pr.first)) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        for (auto &pr : mpfm) {
            if (find_if(fn.begin(), fn.end(),
                        [&](const pair<ll,int>& t){ return t.first == pr.first; }) == fn.end()) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        vector<ll> pri;
        vector<int> an, am;
        {
            unordered_map<ll,int> mpn;
            for (auto &pr : fn) mpn[pr.first] = pr.second;
            for (auto &pr : fm) if (!mpn.count(pr.first)) mpn[pr.first] = 0;
            for (auto &pr : mpn) pri.push_back(pr.first);
            sort(pri.begin(), pri.end());
            an.resize(pri.size());
            am.resize(pri.size());
            for (int i = 0; i < (int)pri.size(); ++i) {
                ll p = pri[i];
                int cntn = 0, cntm = 0;
                for (auto &pr : fn) if (pr.first == p) cntn = pr.second;
                for (auto &pr : fm) if (pr.first == p) cntm = pr.second;
                an[i] = cntn;
                am[i] = cntm;
            }
        }
        unordered_map<ll, pair<ll,ll>> dad;
        unordered_map<ll,int> dist;
        queue<ll> q;
        dad[n] = {-1, -1};
        dist[n] = 0;
        q.push(n);
        bool cokq = false;
        while (!q.empty() && !cokq) {
            ll x = q.front();
            q.pop();
            int d = dist[x];
            if (d >= 200) {
                continue;
            }
            vector<int> ex(pri.size());
            ll tx = x;
            for (int i = 0; i < (int)pri.size(); ++i) {
                ll p = pri[i];
                int cnt = 0;
                while (tx % p == 0) {
                    tx /= p;
                    cnt++;
                }
                ex[i] = cnt;
            }
            if (tx > 1) continue;
            dfs(0,1LL,x,m,d,pri,am,ex,dad,dist,q,cokq);
        }
        if (!cokq) {
            cout << -1 << "\n";
            continue;
        }

        vector<ll> ans;
        ll cur = m;
        while (cur != n) {
            auto pr = dad[cur];
            ll par = pr.first, g = pr.second;
            ans.push_back(g);
            cur = par;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size();
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}

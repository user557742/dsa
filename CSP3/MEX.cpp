#include <bits/stdc++.h>
using namespace std;
int M, N, bst;
vector<vector<int>> g;
void f(int x, int y, unordered_set<int> &s) {
    int v = g[x][y];
    if (s.count(v)) return;
    s.insert(v);
    bst = max(bst, (int)s.size());
    if (y+1 < N) f(x, y+1, s);
    if (x+1 < M) f(x+1, y, s);
    s.erase(v);
}
int gp(const vector<vector<int>> &a, int m, int n, bool pr) {
    unordered_set<int> s;
    int x=0, y=0, cnt=0;
    while (1) {
        int v = a[x][y];
        if (s.count(v)) break;
        s.insert(v);
        cnt++;
        bool r = (y+1<n && !s.count(a[x][y+1]));
        bool d = (x+1<m && !s.count(a[x+1][y]));
        if (pr) {
            if (r) y++;
            else if (d) x++;
            else break;
        } else {
            if (d) x++;
            else if (r) y++;
            else break;
        }
    }
    return cnt;
}
int main(){
	if(fopen("MEX.INP","r")){
		freopen("MEX.INP","r",stdin);
		freopen("MEX.OUT","w",stdout);
	}
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> M >> N;
        g.assign(M, vector<int>(N));
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> g[i][j];

        int ans = 0;
        if (M==1 || N==1) {
            unordered_set<int> s;
            int c=0;
            if (M==1)
                for (int j=0; j<N; j++) {
                    if (s.count(g[0][j])) break;
                    s.insert(g[0][j]); c++;
                }
            else
                for (int i=0; i<M; i++) {
                    if (s.count(g[i][0])) break;
                    s.insert(g[i][0]); c++;
                }
            ans = c;
        }
        else if (M<=13 && N<=13) {
            bst = 0;
            unordered_set<int> s;
            f(0,0,s);
            ans = bst;
        }
        else {
            ans = max(gp(g,M,N,1), gp(g,M,N,0));
        }
        cout << ans << '\n';
    }
    return 0;
}


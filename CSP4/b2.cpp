#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q, a[N], c[N], m;

vector<int> all;

struct Node {
    Node *l, *r;
    int s;
    Node(): l(nullptr), r(nullptr), s(0) {}
};

Node *build(int L, int R) {
    Node *p = new Node();
    if (L == R) return p;
    int M = (L + R) / 2;
    p->l = build(L, M);
    p->r = build(M+1, R);
    return p;
}

Node* upd(Node *pre, int L, int R, int pos) {
    Node *p = new Node(*pre);
    if (L == R) {
        p->s++;
        return p;
    }
    int M = (L + R) / 2;
    if (pos <= M) p->l = upd(pre->l, L, M, pos);
    else p->r = upd(pre->r, M+1, R, pos);
    p->s = p->l->s + p->r->s;
    return p;
}

int kth(Node *A, Node *B, Node *C, Node *D, int L, int R, int k) {
    if (L == R) return L;
    int M = (L + R) / 2;
    int sl = A->l->s + D->l->s - B->l->s - C->l->s;
    if (k <= sl) return kth(A->l, B->l, C->l, D->l, L, M, k);
    else return kth(A->r, B->r, C->r, D->r, M+1, R, k - sl);
}

Node *rt[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    m = all.size();
    for (int i = 1; i <= n; ++i)
        c[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();

    rt[0] = build(0, m - 1);
    for (int i = 1; i <= n; ++i)
        rt[i] = upd(rt[i-1], 0, m - 1, c[i]);

    while (q--) {
        int l, r; cin >> l >> r;
        int tot = (l - 1) + (n - r);
        int k = (tot + 1) / 2;
        int id = kth(rt[l - 1], rt[0], rt[r], rt[n], 0, m - 1, k);
        cout << all[id] << '\n';
    }
}

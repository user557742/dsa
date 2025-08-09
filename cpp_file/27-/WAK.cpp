#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5+1;

int n, m;
struct tv {
    int x1=0, y1=0, x2=0, y2=0;
    tv(int _x1=0,int _y1=0,int _x2=0,int _y2=0)
      : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
} a[maxn];

bool cmp(tv u, tv v){
    return make_pair(u.x2, u.y2) < make_pair(v.x2, v.y2);
}

struct node {
    ll val;
    int l, r;
    node(ll _val= (ll)1e18, int _l=0, int _r=0)
      : val(_val), l(_l), r(_r) {}
};

struct pst {
    int root[maxn];
    node s[40*maxn];
    int cnt;
    int build(int lo, int hi){
        int id = cnt++;
        s[id].val = (ll)1e18;
        if(lo==hi) return id;
        int mid=(lo+hi)/2;
        s[id].l = build(lo,mid);
        s[id].r = build(mid+1,hi);
        return id;
    }
    int upd(int id,int k,ll x,int lo,int hi){
        int nid = cnt++;
        s[nid] = s[id];
        if(lo==hi){
            s[nid].val = min(s[nid].val, x);
            return nid;
        }
        int mid=(lo+hi)/2;
        if(k<=mid) s[nid].l = upd(s[id].l,k,x,lo,mid);
        else       s[nid].r = upd(s[id].r,k,x,mid+1,hi);
        s[nid].val = min(s[s[nid].l].val, s[s[nid].r].val);
        return nid;
    }
    ll get(int id,int u,int v,int lo,int hi){
        if(u>hi||v<lo) return (ll)1e18;
        if(u<=lo&&hi<=v) return s[id].val;
        int mid=(lo+hi)/2;
        return min(
            get(s[id].l,u,v,lo,mid),
            get(s[id].r,u,v,mid+1,hi)
        );
    }
} t;

int tx2[maxn];
ll dp[maxn];
int tmp[40*maxn];
int j = 0;

// giữ lại gg, nó sẽ dùng j sau khi unique
int gg(int x){
    return lower_bound(tmp+1, tmp+j+1, x) - tmp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    // thêm điểm đích
    a[++m] = tv(n,n,n,n);

    sort(a+1, a+m+1, cmp);

    // 1) Gom tọa độ y
    for(int i = 1; i <= m; i++){
        tx2[i] = a[i].x2;
        tmp[++j] = a[i].y1;
        tmp[++j] = a[i].y2;
    }
    sort(tmp+1, tmp+j+1);
    // 2) Loại bỏ duplicate, cập nhật j
    int K = unique(tmp+1, tmp+j+1) - (tmp+1);
    j = K;

    // 3) Nén trực tiếp vào a[i]
    for(int i = 1; i <= m; i++){
        a[i].y1 = gg(a[i].y1);
        a[i].y2 = gg(a[i].y2);
    }

    // khởi tạo dp
    for(int i = 1; i <= m; i++){
        dp[i] = (ll)a[i].x1 + a[i].y1;
    }

    // 4) Reset và build PST trên [1..j]
    t.cnt = 0;
    t.root[0] = t.build(1, j);

    // 5) DP chính, tìm ver chỉ trên [1..i-1], bỏ hẳn if thừa
    for(int i = 1; i <= m; i++){
        int ver = int(upper_bound(tx2+1, tx2+i, a[i].x1) - tx2) - 1;
        if(ver >= 1){
            ll best = t.get(t.root[ver], 1, a[i].y1, 1, j);
            dp[i] = min(dp[i], best + a[i].x1 + (ll)a[i].y1);
        }
        ll put = dp[i] - (ll)a[i].x2 - (ll)a[i].y2;
        t.root[i] = t.upd(t.root[i-1], a[i].y2, put, 1, j);
    }

    cout << dp[m] << "\n";
    return 0;
}

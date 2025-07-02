#include <bits/stdc++.h>
using namespace std;
int rrd(int l, int r) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(l, r);
    return dist(gen);
}
vector<tuple<int,int,int>> generateRandomTree(int n) {
    vector<tuple<int,int,int>> edges;
    edges.reserve(n-1);
    for (int i = 2; i <= n; ++i) {
        int p = rand() % (i - 1) + 1;
        int w = rand() % 2000 + 1;
        edges.emplace_back(p, i, w);
    }
    random_shuffle(edges.begin(), edges.end());

    return edges;
}

string a[3]={"CHANGE","NEGATE","QUERY"};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(static_cast<unsigned>(time(nullptr)));
    int n=rrd(2,2000);
    int q=rrd(1,2000);
    cout<<n<<" "<<q<<"\n";
    auto tree = generateRandomTree(n);
     for (const auto &edge : tree) {
        int u, v, w;
        tie(u, v, w) = edge;
        cout << u << " " << v << " " << w << "\n";
    }
    while(q--){
        int l=rrd(0,2);
        if(l==0){
            int k=rrd(1,n-1);
            int x=rrd(1,1000);
            cout<<a[l]<<" "<<k<<" "<<x<<"\n";
        }
        if(l==1){
            int u=rrd(1,n),v=rrd(1,n);
            cout<<a[l]<<" "<<u<<" "<<v<<"\n";

        }
        if(l==2){
            int u=rrd(1,n),v=rrd(1,n);
            cout<<a[l]<<" "<<u<<" "<<v<<"\n";
        }
    }
    return 0;
}

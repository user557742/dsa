#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

void solve(){
    cin >> n >> a >> b;
    // Using 1-indexing by adding a dummy character at the beginning is optional,
    // but here we use 0-indexing for clarity.
    
    // Counters for ones in the two components:
    // Component 1: a at odd indices (0-indexed: even positions) and b at even indices (0-indexed: odd positions)
    // Component 2: a at even indices (0-indexed: odd positions) and b at odd indices (0-indexed: even positions)
    // Note: When converting from 1-indexing to 0-indexing, parity flips.
    // To keep the idea clear, we can simply follow the original 1-indexing by prepending a space.
    a = " " + a;
    b = " " + b;
    
    int lea = 0, chana = 0, leb = 0, chanb = 0;
    for (int i = 1; i <= n; i++){
        if(a[i] == '1'){
            if(i % 2 == 0)
                chana++;  // a even positions
            else
                lea++;    // a odd positions
        }
        if(b[i] == '1'){
            if(i % 2 == 0)
                chanb++;  // b even positions
            else
                leb++;    // b odd positions
        }
    }
    
    // For Component 1 (a odd and b even):
    // Capacity available for ones in b is the number of even positions in b.
    int cap1 = n / 2;  // floor(n/2)  (because for 1-indexed positions, even positions are n/2)
    // For Component 2 (a even and b odd):
    int cap2 = (n + 1) / 2; // ceil(n/2)
    
    int u = lea + chanb;  // ones in component 1
    int v = chana + leb;  // ones in component 2
    
    if(u > cap1 || v > cap2){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct V{
    int nex[26];
    int cnt=0;
    V(int _cnt=0) : cnt(_cnt) {
        cnt=0;
        memset(nex,0,sizeof(nex));
    }
};
vector<V> trie(1);
void them(string x){
    int u=0;
    for(char c:x){
        int gt=c-'a';
         if (gt < 0 || gt >= 26) continue;
        if(trie[u].nex[gt]==0){
            trie[u].nex[gt]=trie.size();
            trie.push_back(V(0));
        }
        u=trie[u].nex[gt];
        trie[u].cnt++;
    }
}
bool kt(string x){
    int u=0;
    for(char c:x){
        int gt=c-'a';
         if (gt < 0 || gt >= 26) continue;
        int v=trie[u].nex[gt];
        if(v==0) return 0;
        if(trie[v].cnt==0) return 0;
        u=v;
    }
    return 1;
}
void xoa(string x){
    if(!kt(x)) return;
    int u=0;
    for(char c:x){
        int gt=c-'a';
         if (gt < 0 || gt >= 26) continue;
        int v=trie[u].nex[gt];
        if(v==0) return ;
        if(trie[v].cnt==0) return ;
        trie[v].cnt--;
        u=v;

    }
}
int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int q;cin>>q;
    memset(trie[0].nex,0,sizeof(trie[0].nex));
    while(q--){
        int l;string x;cin>>l>>x;
        //x.erase(x.begin());
        //x.pop_back();
        if(l==1) them(x);
        if(l==2) xoa(x);
        if(l==3){
            if(kt(x)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}

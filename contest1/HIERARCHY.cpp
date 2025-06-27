#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+1;
struct E{
    int u,v;
} e[maxn];
int n;
int pre[maxn];
E tv[maxn];
int q;
inline void calcsub3(int u,int v){
    for(int i=1;i<=n;i++){
        pre[i]=0;
    }
    for(int i=1;i<n;i++){
        if((e[i].u==u&&e[i].v==v)||(e[i].u==v&&e[i].v==u)){
            int tmpu=e[i].u;
            int tmpv=e[i].v;
            e[i].u=tmpv;e[i].v=tmpu;
        }
        
    }
    bool ok=0;
    for(int i=1;i<n;i++){
        pre[e[i].v]=e[i].u;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(pre[i]==0) cnt++;
    }
    if(cnt>=2) ok=0;
    else ok=1;
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}
inline void sub3(){
    calcsub3(0,0);
    for(int i=1;i<=q;i++){
        calcsub3(tv[i].u,tv[i].v);
    }
}
void sub4(){
    calcsub3(0,0);
}
void sub5(){
    cout<<"YES\n";
    for(int i=1;i<=q;i++) cout<<"YES\n";
}
int main(){
    if(fopen("HIERARCHY.INP","r")){
        freopen("HIERARCHY.INP","r",stdin);
        freopen("HIERARCHY.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>e[i].u>>e[i].v;
    }
    cin>>q;
    for(int i=1;i<=q;i++) cin>>tv[i].u>>tv[i].v;
    sub3();
}
/*
4
2 1
2 3
1 4
4 
4 1
4 1
3 2
1 4
*/
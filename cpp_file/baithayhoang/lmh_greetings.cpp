#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
int n, d[maxn], dir[maxn], remn[maxn], pos[maxn], nxt[maxn], ds[maxn];
int conv(string u){
    int s=0;
    for(int i=1;i<(int)u.size();i++) s=s*10+(u[i]-'0');
    return s;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        string x;
        cin>>x;
        if(x[0]=='-'){
            d[i]=-conv(x);
        } else {
            d[i]=conv(x);
        }
        dir[i]=(d[i]>0?1:-1);
        remn[i]=abs(d[i]);
        pos[i]=i;
    }
    int T=0;
    for(int i=1;i<=n;i++) T=max(T,remn[i]);
    auto nx=[&](int p){
        p+=1;
        if(p>n) p=1;
        return p;
    };
    for(int t=1;t<=T;t++){
        for(int i=1;i<=n;i++){
            if(remn[i]>0){
                int p=pos[i]+dir[i];
                if(p==0) p=n;
                if(p>n) p=1;
                nxt[i]=p;
            } else nxt[i]=pos[i];
        }
        for(int i=1;i<=n;i++){
            if(remn[i]<=0) continue;
            for(int j=i+1;j<=n;j++){
                if(remn[j]<=0) continue;
                if(dir[i]+dir[j]!=0) continue;
                bool sss = nxt[i]==nxt[j];
                bool css = nxt[i]==pos[j]&&nxt[j]==pos[i];
                if(sss||css){
                    ds[i]++;
                    ds[j]++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(remn[i]>0){
                pos[i]=nxt[i];
                remn[i]--;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<ds[i]<<"\n";
    return 0;
}

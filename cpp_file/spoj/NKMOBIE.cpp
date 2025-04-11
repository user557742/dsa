#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct fenwitch{
    vector<ll> s;
    void init(int n){
        s.resize(n+1,0);
    }
    ll get(int p){
        int idx=p;ll ds=0;
        while(idx>0){
            ds+=s[idx];
            idx-=idx&(-idx);    
        }
        return ds;
    }
    void upd(int k,int x){
        int idx=k;
        while(idx<=(int)s.size()-1){
            s[idx]+=x;
            idx+=idx&(-idx);
        }
    }
};
struct bit2d{
    vector<fenwitch> s;
    void init(int n){
        s.resize(n+1);
        for(int i=1;i<=n;i++) s[i].init(n);
    }
    void upd(int u,int v,int x){
        int idx=u;
        while(idx<=(int)s.size()-1){
            s[idx].upd(v,x);
            idx+=idx&(-idx);
        }
    }
    ll get(int u,int v){
        int idx=u;ll ds=0;
        while(idx>0){
            ds+=s[idx].get(v);
            idx-=idx&(-idx);
        }
        return ds;
    }
    ll getans(int u,int v,int x,int y){
        return get(x,y)-get(x,v-1)-get(u-1,y)+get(u-1,v-1);
    }
} b2d;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int ppo;
    while(cin>>ppo){
        if(ppo==0){
            int n;cin>>n;
            b2d.init(n);
        }
        if(ppo==1){
            int x,y,a;cin>>x>>y>>a;
            x++;y++;
            b2d.upd(x,y,a);
        }
        if(ppo==2){
            int u,v,x,y;
            cin>>u>>v>>x>>y;
            u++;v++;x++;y++;
            cout<<b2d.getans(u,v,x,y)<<"\n";
        }
        if(ppo==3){
            break;
        }
    }
}
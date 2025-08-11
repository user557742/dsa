#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+1;
struct task{
    long long du,dl;
} a[maxn];
int n;
bool cmp(task u,task v){
    return make_pair(u.du,u.dl)<make_pair(v.du,v.dl);
};
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].du>>a[i].dl;
    sort(a+1,a+n+1,cmp);
    long long  tg=0;
    long long kq=0;
    for(int i=1;i<=n;i++){
        tg+=a[i].du;
        kq+=a[i].dl-tg;
    }
    cout<<kq;
    return 0;
}

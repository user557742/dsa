#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const int mod=1e9+7;
typedef long long ll;
#define rei(i,l,r) for (int i=l;i<=r;i++)
#define red(i,r,l) for (int i=r;i>=l;i--)
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ub upper_bound
#define lb lower_bound
int n,m;
int s[maxn];
bool ok[maxn];
vector<string> u;
int x[maxn];
void back(int h){
    if(h>n){
        string ds=" ";
        rei(i,1,n) ds.push_back(char(x[i]+'0'));
        u.push_back(ds);
        return ;
    }
    if(ok[h]) x[h]=0;
    else{
        rei(i,0,2){
            x[h]=i;
            back(h+1);
        }
    }

}
pair<int,string> solve(int a,int b,int l,vector<int> lx){
    int ds=0;
    string kq="";
    for(string d:u){
        bool bann=0;
        for(int y:lx){
            if(d[y]!='0'){
                bann=1;
                break;
            }
        }
        if(bann) continue;
        ll s1=0,s2=0;
        int ss=0;
        rei(i,1,n){
            if(d[i]=='1') s1+=s[i];
            if(d[i]=='2') s2+=s[i];
            if(d[i]!='0') ss++;
        }
        if(s1>a) continue;
        if(s2>b) continue;
        if(ss>ds){
            ds=ss;
            kq=d;
        }
    }
    return {ds,kq};
}
int main(){
	faster
    cin>>n>>m;
    rei(i,1,n) cin>>s[i];
    back(1);
    bool fi=0;
    rei(i,1,m){
        int a,b;
        int l;
        vector<int> lx;
        cin>>a>>b>>l;
        rei(i,1,l){
            int g;cin>>g;
            lx.push_back(g);
        }
        pair<int,string> gt=solve(a,b,l,lx);
        if(!fi){
            cout<<gt.first<<"\n";
            rei(i,1,n) cout<<gt.second[i];
            cout<<"\n";
            fi=1;
        }
        else cout<<gt.first<<" ";
    }

	return 0;
}

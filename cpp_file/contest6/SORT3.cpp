// chi ra mot phuong an sap xep sao cho hai so nguyen lien tiep khong chia het cho 3
// 0 0 0 0 1 1 1 2 2 2
// 1 1 1 0 2 2 2
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 1e5+1;
#define fi first
#define se second
#define rei(i,a,b) for(int i=a;i<=b;i++)
int n;
int a[maxn];
pair<int,int> p[maxn];
int ds[maxn];
int main(){
    if(fopen("SORT3.INP","r")){
        freopen("SORT3.INP","r",stdin);
        freopen("SORT3.OUT","w",stdout);
    }
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    rei(i,1,n) cin>>a[i];
    rei(i,1,n){
        p[i]={a[i]%3,i};
    }
    sort(p+1,p+n+1);
    int so0=0,so1=0,so2=0;
    rei(i,1,n){
        if(p[i].fi==0) so0++;
        if(p[i].fi==1) so1++;
        if(p[i].fi==2) so2++;
    }
    if(so1!=0&&so2!=0&&so0==0){
        cout<<"impossible";
        return 0;
    } 
    //if(so1!=0&&so2!=0&&so0!=0){
    if(so0>so1+so2+1){
        cout<<"impossible";
        return 0;
    }
    //}
    int lim=2*(so1+so2)+1;
    int idx=0;
    int st1=0;
    //cout<<lim;
    rei(i,1,n){
        if(p[i].fi==1){
            st1=i;
            break;
        }
    }
    rei(i,st1,n){
        idx+=2;
        ds[idx]=p[i].second;
    }
    int st0=1;
    rei(i,2,lim-1){
        if(a[ds[i]]%3==0&&a[ds[i-1]]%3==1&&a[ds[i+1]]%3==2){
            st0=i;
            break;
        }
    }
    int j=1;
    for(int i=st0;i>=1;i--) if(j<st1){
        if(ds[i]==0){
            ds[i]=p[j].se;
            j++;
        } 
    }
    rei(i,st0+1,lim) if(j<st1){
        if(ds[i]==0){
            ds[i]=p[j].se;
            j++;
        }
    }
    rei(i,1,lim) if(ds[i]!=0) cout<<a[ds[i]]<<" ";
}
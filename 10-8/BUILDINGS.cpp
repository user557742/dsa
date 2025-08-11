#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1;
int n;
int a[maxn],l[maxn],r[maxn];
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=1e9;
    a[0]=1e9;
    for(int i=1;i<=n;i++){
        int tmpa=a[i];
        a[i]=0;
        for(int j=1;j<=n;j++){
            l[j]=0;r[j]=0;
        } 
        int ds=0;
        for(int j=1;j<=n;j++) if(i!=j){
            int k=j-1;
            while(a[j]>=a[k]&&k>0) k=l[k];
            l[j]=k;
        }
        for(int j=n;j>=1;j--) if(i!=j){
            int k=j+1;
            while(a[j]>=a[k]&&k<=n){
                k=r[k];
            }
            r[j]=k;
        }
        for(int j=1;j<=n;j++) if(i!=j){
            l[j]++;r[j]--;
        }
        for(int j=1;j<=n;j++) if(i!=j){
            ds+=r[j]-l[j]+1;
        }
        cout<<ds<<"\n";
        a[i]=tmpa;
    }
}
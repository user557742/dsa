/*
bài toán ban đầu --->  https://codeforces.com/contest/2102/problem/D
*/
/*
ý đồ của tôi là : sau khi tối ưu cho các vị trí lẻ tôi sẽ tìm cách tối ưu các vị trí chẵn .
 tôi phát hiện ra rằng cách để đổi chỗ các vị trí chẵn sao cho các vị trí lẻ không bị ảnh hưởng . 
 đó là nếu có 6 số a b c d e f --> a d e b c f ---> a d c f e b 
 đo đó tôi đã đơn giản hóa vấn để bằng cách coi như các phần tử lể không tồn tại và gom thành một bài toán con :
*/
/*cho một dãy số có n phần tử có giá trị khác nhau . và có thể thực hiện thao tác sau tùy ý :
    + chọn i phần tử ai (i<=n-2)
    + hoán đổi ai a[i+1] a[i+2] --> a[i+1] a[i+2] a[i] 
hãy đưa ra dãy có thứ tự từ điển nhỏ nhất*/
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e5+1;
int pos[maxn];
int tmp[maxn];
int a[maxn];
pair<int,int> p[maxn];
int ds[maxn];
int b[maxn];
int h[maxn];
void solve(){
    a[-1]=0;
    int n;cin>>n;
    for(int i=1;i<=n;i++) ds[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    bool ol=0;
    if(n%2==1) {
        ol=1;
        n--;
    }
    int cnt=1;
    for(int i=1;i<=n;i++) if(i%2==1){
        p[cnt]={a[i],a[i+1]};
        cnt++;
    } 
    cnt--;
    sort(p+1,p+cnt+1);
    for(int i=1;i<=cnt;i++){
        h[i]=p[i].first;
        b[i]=p[i].second;
    }
    if(ol){
        h[cnt+1]=a[n+1];
        sort(h+1,h+cnt+2);
        for(int i=1;i<=cnt+1;i++){
            ds[2*i-1] =h[i];
        }
    }
    else{
        sort(h+1,h+cnt+1);
        for(int i=1;i<=cnt;i++) ds[2*i-1]=h[i];
    }
    int sign=1;
    int pivot=0;
    for(int i=1;i<=cnt;i++) tmp[i]=b[i];
    sort(tmp+1,tmp+cnt+1);
    int maxval=tmp[cnt];
    int smaxval=tmp[cnt-1];
    for(int i=1;i<=cnt;i++){
       
        if(b[i]==maxval) pivot=i;
        
    }
    for(int i=1;i<=cnt;i++) pos[b[i]]=i;
    int cur=1;
    if(pos[smaxval]<pos[maxval]) cur=1;
    else cur=-1;
    for(int i=1;i<=cnt-2;i++){
        int x=tmp[i];
        if(pos[x]>pivot){
            int g=pos[x]-i;
            if(g%2!=0) sign*=-1;
            ds[2*i]=tmp[i];
        }else{
            ds[2*i]=tmp[i];
        }
    }
    if(sign*cur==1){
        ds[2*cnt-2]=smaxval;
        ds[2*cnt]=maxval;
    }
    else{
        ds[2*cnt-2]=maxval;
        ds[2*cnt]=smaxval;
    }
    
    if(ol){
        n++;
    }
    for(int i=1;i<=n;i++) cout<<ds[i]<<" ";
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
} 
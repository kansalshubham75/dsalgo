#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
int rec(vc<vc<int>>& b,int curr,int myc,int det,bool usedDet,int val){
    if(curr<0)return 0;
    if(b[curr][myc]==2){
        int max_sc=INT_MIN;
        if(!usedDet){
        if(myc-1>=0)
            max_sc=max(max_sc,rec(b,curr-1,myc-1,4,1,val));
        if(myc+1<b.size())
            max_sc=max(max_sc,rec(b,curr-1,myc+1,4,1,val));
        max_sc=max(max_sc,rec(b,curr-1,myc,4,1,val));
        }
        return max_sc;
    }
    int c=0;
    if(b[curr][myc]==1)c=1;
    else if(b[curr][myc]==2)c=(det>0)?0:-1;
    if(val+c<0)return INT_MIN;
    int max_sc=INT_MIN;
    if(myc-1>=0)
        max_sc=max(max_sc,rec(b,curr-1,myc-1,det+(usedDet?-1:0),usedDet,val));
    if(myc+1<b.size())
        max_sc=max(max_sc,rec(b,curr-1,myc+1,det+(usedDet?-1:0),usedDet,val));
    max_sc=max(max_sc,rec(b,curr-1,myc,det,usedDet,val));
    return max_sc+c;
}
void solve(){
    int n;
    cin>>n;
    vc<vc<int>> b(n,vc<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>b[i][j];
    }
    cout<<rec(b,n-1,n/2,0,0,0)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
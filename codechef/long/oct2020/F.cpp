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
void solve(){
    int w,h,n,m;
    cin>>w>>h>>n>>m;
    vc<int> x(n),y(m);
    read(x);read(y);
    if(n==1){
        cout<<0<<endl;return;
    }
    if(m==1){
        cout<<1<<endl;return;
    }
    set<int> xs;
    set<int> ys;
    set<int> common;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            xs.insert(abs(x[j]-x[i]));
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m;j++){
            int diff=abs(y[j]-y[i]);
            ys.insert(diff);
            if(xs.count(diff))common.insert(diff);
        }
    }
    int max_=0;
    for(int d=1;d<=min(w,h);d++){
        if(common.find(d)==common.end() && xs.count(d)){
            auto itr=ys.upper_bound(d);
            if(itr==ys.end())break;
            max_=1;
            while(itr!=ys.end()){
                int curr=*itr;
                int other=curr-d;
                if(d!=other && common.find(other)==common.end() && xs.count(other)){
                    cout<<common.size()+2<<endl;return;
                }
                itr++;
            }
        }
    }
    cout<<common.size()+max_<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
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
int extEuclid(int a,int b,int& x,int& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int ret=extEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return ret;
}
void solve(){
    int a,b;
    while(cin>>a && cin>>b){
        int x,y;
        extEuclid(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

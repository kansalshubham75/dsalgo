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
ll extEuclid(ll a,ll b,ll& x,ll& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll ret=extEuclid(b,a%b,x1,y1);
    x=y1;
    y=x1-y1*(a/b);
    return ret;
}

void solve(){
    while(1){
        ll n,m,k,l;
        cin>>n>>m>>k>>l;
        if(!(n || m || k || l))break;
        ll c=k-n,x,y;
        ll g=extEuclid(m,l,x,y);
        if((m*x)+(l*y)!=c)cout<<"Impossible";
        else{
            cout<<k+(-1*l*y);
        }
        cout<<endl;
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

#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
void solve(){
    ll x,y,k;
    cin>>x>>y>>k;
    ll ans=k;   //exch for coal
    if(x>=(k+(k*y))){
        cout<<k+1<<endl;
        return;
    }
    ll reqd=k+(k*y)-x;
    ans+=(reqd/(x-1))+1;
    if(reqd%(x-1)!=0)ans++;
    cout<<ans<<endl;
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
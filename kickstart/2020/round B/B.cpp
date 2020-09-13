#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve(){
    ll n,d;
    cin>>n>>d;
    vector<ll> buses(n);
    for(ll i=0;i<n;i++)
        cin>>buses[i];
    ll lo=1,hi=d,ans=1;
    while(lo<hi){
        ll mid=lo+((hi-lo+1)/2);
        ll prev=mid;
        for(ll i=0;i<n;i++){
            ll offset=prev%buses[i];
            if(offset>0){
                prev+=(buses[i]-offset);
            }
        }
        if(prev<=d){
            lo=mid;
        }else{
            hi=mid-1;
        }
    }
    cout<<lo<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}
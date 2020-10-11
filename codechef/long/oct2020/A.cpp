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
    ll n,k;
    cin>>n>>k;
    vc<ll> arr(n);
    for(ll& i:arr)cin>>i;
    ll carry=0;
    ll total=0;
    for(int i=0;i<n;i++){
        ll pendingQ=arr[i]+carry;
        total+=arr[i];
        if(pendingQ<k){
            cout<<i+1<<endl;return;
        }
        carry=pendingQ-k;
    }
    ll days=(total/k)+1;

    cout<<days<<endl;
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
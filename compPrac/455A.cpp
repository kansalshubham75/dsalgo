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
    int n;
    cin>>n;
    vc<int> arr(n);read(arr);
    vector<pll> a;
    sort(arr.begin(),arr.end());
    for(int i:arr){
        int size=a.size();
        if(size && a[size-1].first==i)a[size-1].second++;
        else    a.push_back({i,1});
    }
    vc<ll> dp(a.size(),0);
    dp[0]=a[0].first*a[0].second;
    for(int i=1;i<a.size();i++){
        ll inc=a[i].first*a[i].second;
        if(a[i-1].first+1==a[i].first){
            ll prev=i-2<0?0:dp[i-2];
            dp[i]=max(inc+prev,dp[i-1]);
        }else{
            dp[i]=inc+dp[i-1];
        }
    }
    cout<<dp[a.size()-1];
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
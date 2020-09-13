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
    int n,x;
    cin>>n>>x;
    vc<int> arr(n);
    read(arr);
    sort(arr.begin(),arr.end());
    vc<ll> dp(n+1,0LL);
    for(int i=n-1;i>=0;i--){
        int minpeople=ceil((double)x/arr[i]);
        if(i+minpeople<=n){
            dp[i]=max(dp[i+1],dp[i+minpeople]+1);
        }else{
            dp[i]=dp[i+1];
        }
    }
    // for(int i:dp)
    // cout<<i<<" ";
    // cout<<endl;
    cout<<dp[0]<<endl;
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
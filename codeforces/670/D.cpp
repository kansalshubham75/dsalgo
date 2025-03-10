#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
ll mod=1e9+7;
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
ll helper(int sum,vc<ll>& dp){
    if(sum==0)return 1;
    if(dp[sum]!=-1)return dp[sum];
    dp[sum]=0;
    for(int i=3;i<=sum;i++){
        if(sum-i<0)break;
        dp[sum]=(dp[sum]+helper(sum-i,dp))%mod;
    }
    return dp[sum];
}
void solve(){
    int s;
    cin>>s;
    vc<ll> dp(s+1,-1);
    cout<<helper(s,dp)%mod;
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
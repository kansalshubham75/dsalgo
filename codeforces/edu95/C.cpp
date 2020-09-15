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
int helper(vc<int>& arr,int curr,vc<int>& dp){
    int n=arr.size();
    if(curr>=n)return 0;
    if(dp[curr]!=-1)return dp[curr];
    int b1=arr[curr];
    int b2=curr+1<n?arr[curr+1]:0;
    return dp[curr]=min(b1+min(helper(arr,curr+2,dp),helper(arr,curr+3,dp)),
    b1+b2+min(helper(arr,curr+3,dp),helper(arr,curr+4,dp)));
}
void solve(){
    int n;
    cin>>n;
    vc<int> arr(n);read(arr);
    vc<int> dp(n,-1);
    cout<<helper(arr,0,dp)<<endl;
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
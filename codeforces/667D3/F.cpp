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
int helper(string& s,string& t,int i,int j,int k,vc<vc<vc<int>>>& dp){
    if(k<0) return 0;
    if(j==2)    return 1;
    if(i==s.length())    return 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    dp[i][j][k]=0;
    if(s[i]==t[j]){
        dp[i][j][k]=helper(s,t,i+1,j+1,k,dp)+helper(s,t,i+1,j,k,dp);
    }else{
        dp[i][j][k]=max(helper(s,t,i+1,j+1,k-1,dp)+helper(s,t,i+1,j,k-1,dp),helper(s,t,i+1,j,k,dp));
    }
    return dp[i][j][k];
}
void solve(){
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    vc<vc<vc<int>>> dp(n+1,vc<vc<int>>(3,vc<int>(k+1,-1)));
    cout<<helper(s,t,0,0,k,dp)<<endl;
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
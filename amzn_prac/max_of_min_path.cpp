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
    vc<vc<int>> grid={{1,2,3},{1,5,6},{7,8,9}};
    int n=grid.size();
    int m=grid[0].size();
    vc<vc<int>> dp(n,vc<int>(m,0));
    dp[0][0]=INT_MAX;
    grid[n-1][m-1]=INT_MAX;
    for(int i=1;i<n;i++)dp[i][0]=min(grid[i][0],dp[i-1][0]);
    for(int i=1;i<m;i++)dp[0][i]=min(grid[0][i],dp[0][i-1]);
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=min(grid[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<dp[n-1][m-1];
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
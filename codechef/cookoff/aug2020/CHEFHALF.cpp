#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<int>> dp(n+1,vector<int>(2,1));
    int ans=0;
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]<0){
            dp[i][0]=dp[i-1][0]+1;
            ans+=(dp[i][0]/2);
        }else{
            dp[i][1]=dp[i-1][1]+1;
            ans+=(dp[i][1]/2);
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(int arr[],int n){
    for(int i=0;i<n;i++)
        cin>>arr[i];
}
ll max_(ll v1,ll v2){
    return v1>v2?v1:v2;
}
void solve(){
    int n;
    cin>>n;
    int arr1[n],arr2[n];
    read(arr1,n);
    read(arr2,n);
    ll dp[2][n];
    dp[0][0]=arr1[0];
    dp[1][0]=arr2[0];
    for(int i=1;i<n;i++){
        dp[0][i]=max_(dp[0][i-1],max_(dp[1][i-1],(i-2>=0?dp[0][i-2]:0))+arr1[i]);
        dp[1][i]=max_(dp[1][i-1],max_(dp[0][i-1],(i-2>=0?dp[1][i-2]:0))+arr2[i]);
    }
    cout<<max_(dp[0][n-1],dp[1][n-1])<<endl;
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
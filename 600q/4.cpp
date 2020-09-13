#include <iostream>
#include<vector>
using namespace std;


int lis(vector<int>& arr, vector<int>& dp){
    dp[0]=arr[0];
    int max_=dp[0];
    for(int i=1;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]);
            }
        }
        dp[i]+=arr[i];
        max_=max(max_,dp[i]);
    }
    return max_;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    vector<int> dp(n,0);
	    cout<<lis(arr,dp)<<endl;
	}
	return 0;
}
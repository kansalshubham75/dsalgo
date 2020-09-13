#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int digits=0;
int helper(vector<int>& binval,int i,int sum,int n,vector<unordered_map<int,int>>& dp){
    if(i==n)
        return 0;
  	if(dp[i].find(sum)!=dp[i].end())
      	return dp[i][sum];
    int count=0;
    count+=helper(binval,i+1,sum+binval[i],n,dp);
    count+=helper(binval,i+1,sum,n,dp);
  	if((sum+binval[i])==0)
      count++;
    return dp[i][sum]=count;
}
pair<int,int> binEval(int a){
    pi ans={0,0};
    while(a!=0){
        int r=a%2;
        a/=2;
        r==0?ans.first++:ans.second++;
    }
    return ans;
}
int main(){
    int n,max_=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        max_=max(max_,arr[i]);
    }
  	vector<unordered_map<int,int>> dp(n);
    vector<int> binval(n);
    pi maxdigits=binEval(max_);
    digits=maxdigits.first+maxdigits.second;
    for(int i=0;i<n;i++){
        pi temp=binEval(arr[i]);
        temp.first=digits-temp.second;
        binval[i]=temp.second-temp.first;
    }
    int rec=helper(binval,0,0,n,dp);
    vector<int> ans;
    while(rec!=0){
        int r=rec%2;
        rec/=2;
        ans.insert(ans.begin(),r);
    }
    int x=ans.size();
    if(x==0){
        for(int i=0;i<digits;i++)
            cout<<0;
        digits=0;
      	return 0;
    }
  	int zeroes=digits-x;
    for(int i=0;i<zeroes;i++)
        cout<<0;
    for(int i=0;i<x;i++)
        cout<<ans[i];
  	digits=0;
    return 0;
}
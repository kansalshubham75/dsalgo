#include <bits/stdc++.h>
using namespace std;
int helper(vector<int>& arr,int idx,int lm,int rm,bool ila){
    if(rm==0)
        return arr[idx];
    // if(dp[rm][idx][lm]!=-1)
    //     return dp[rm][idx][lm];
    int myans=0;
    if(ila && idx>0 && lm>0)
        myans=helper(arr,idx-1,lm-1,rm-1,false)+arr[idx];
    myans=max(myans,helper(arr,idx+1,lm,rm-1,true)+arr[idx]);
    return myans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n,k,z;
        cin>>n>>k>>z;
        vector<int> arr(n);
        vector<vector<vector<int>>> dp(k+1,vector<vector<int>>(n+1,vector<int>(z+1,0)));
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++)
            dp[0][i][0]=arr[i];
        for(int move=1;move<=z;move++){
            for(int idx=0;idx<n;idx++){
                for(int lm=0;lm<z && idx>0;lm++){
                    dp[move][idx][lm]=max(dp[move-1][idx+1][lm-1],)
                }
            }
        }

        cout<<helper(arr,0,z,k,true)<<"\n";
    }
    return 0;
}
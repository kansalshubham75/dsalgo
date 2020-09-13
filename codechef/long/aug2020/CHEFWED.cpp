#include <bits/stdc++.h>
using namespace std;
int rec(int gidx,int guests[],int dp[],int n,int k,unordered_map<int,unordered_map<int,int>>& m){
    if(gidx==n)
        return 0;
    if(dp[gidx]!=-1)
        return dp[gidx];
    int myans=INT_MAX;
    for(int i=gidx;i<n;i++){
        myans=min(myans,k+m[gidx][i]+rec(i+1,guests,dp,n,k,m));
    }
    return dp[gidx]=myans;
}
void solve(){
    int k,n;
    cin>>n>>k;
    int guests[n],dp[n+1];
    for(int i=0;i<n;i++)
        cin>>guests[i];
    memset(dp,-1,sizeof(dp));
    unordered_map<int,unordered_map<int,int>> m;
    for(int i=0;i<n;i++){
        unordered_map<int,int> s;
        s[guests[i]]++;
        for(int j=i+1;j<n;j++){
            m[i][j]=m[i][j-1];
            if(s.find(guests[j])!=s.end()){
                m[i][j]+=(1+(s[guests[j]]==1));
            }
            s[guests[j]]++;
        }
    }
    cout<<rec(0,guests,dp,n,k,m)<<endl;
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
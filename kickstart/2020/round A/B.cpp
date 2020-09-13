#include <bits/stdc++.h>
using namespace std;
int helper(vector<vector<int>>& stacks,vector<vector<int>>& dp,int stno,int p){
    
}
void solve(){
    int n,k,p;
    cin>>n>>k>>p;
    vector<vector<int>> stacks(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++)
            cin>>stacks[i][j];
    }
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>>& g,int src){
    
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1,vector<int>(n+1,-1));
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
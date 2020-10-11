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
vector<int> par;
vector<int> disc;
vector<int> low;
int t=1;
int points=0;
void dfs(int u,vector<vector<int>>& g){
    disc[u]=low[u]=t;
    t++;
    for(int v:g[u]){
            if(v==par[u])continue;
            if(disc[v]==0){
                par[v]=u;
                dfs(v,g);
                if(low[v]<disc[u]){
                    cout<<u<<endl;
                    points++;
                }
                low[u]=min(low[u],low[v]);
            }else{
                low[u]=min(low[u],disc[v]);
            }
    }
}
void solve(){
    vector<vector<int>> g;
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
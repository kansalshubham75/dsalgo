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
void dfs(int u,int& t,int osrc,vc<int>& disc,vc<int>& low,vc<int>& par,vc<vc<int>>& g,vc<int>& ans){
    disc[u]=low[u]=t;
    t++;
    int children=0;
    for(int v:g[u]){
        if(v==par[u])continue;
        if(disc[v]==-1){
            children++;
            par[v]=u;
            dfs(v,t,osrc,disc,low,par,g,ans);
            if(low[v]>=disc[u] && u!=osrc)ans.push_back(u);
            low[u]=min(low[u],low[v]);
        }else{
            low[u]=min(low[u],disc[v]);
        }
    }
    if(u==osrc && children>=2)ans.pb(u);
}
void solve(){
    vc<vc<int>> edges={{0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 5}, {5, 6}, {3, 4}};
    int n=7;
    vc<vc<int>> g(7);
    for(auto e:edges){
        g[e[0]].pb(e[1]);
        g[e[1]].pb(e[0]);
    }
    vc<int> low(n,-1);
    vc<int> disc(n,-1);
    vc<int> par(n,-1);
    vc<int> ans;
    int t=1;
    dfs(0,t,0,disc,low,par,g,ans);
    for(int i:ans)cout<<i<<" ";
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
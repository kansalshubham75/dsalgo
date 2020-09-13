#include <bits/stdc++.h>
using namespace std;
void dfs(int u,int day,int pop,vector<vector<int>>& g,unordered_set<int>& vis,vector<bool>& visited,vector<int>& f,vector<int>& ans){
    f[u]-=min(f[u],pop);
    if(f[u]==0)
        ans[u]=day;
    visited[u]=true;
    for(int v:g[u]){
        if(!visited[v] && vis.find(v)==vis.end())
            dfs(v,day,pop,g,vis,visited,f,ans);
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> g(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> p(n+1);
    vector<int> pop(n+1);
    vector<int> f(n+1);
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
        cin>>pop[i];
    for(int i=1;i<=n;i++)
        cin>>f[i];
    unordered_set<int> vis;
    vector<int> ans(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis.find(p[i])==vis.end()){
            vector<bool> visited(n+1,false);
            dfs(p[i],i,pop[p[i]],g,vis,visited,f,ans);
            vis.insert(p[i]);
        }else{
            if(ans[p[i]]==-1){
                f[p[i]]-=min(pop[p[i]],f[p[i]]);
                if(f[p[i]]==0)
                    ans[f[p[i]]]=i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
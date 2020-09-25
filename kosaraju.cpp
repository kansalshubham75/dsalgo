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
void dfs(int u,vc<vc<int>>& g,stack<int>& st,vector<bool>& vis,bool shouldFill){
    vis[u]=true;
    for(int v:g[u]){
        if(!vis[v])dfs(v,g,st,vis,shouldFill);
    }
    if(shouldFill)st.push(u);
}

void solve(vc<vc<int>>& g){
    int n=g.size();
    vc<bool> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i,g,st,vis,true);
    }
    vc<vc<int>> newg(n);
    for(int u=0;u<n;u++){
        for(int v:g[u])newg[v].pb(u);
    }
    vis.clear();
    int count=0;
    vis.assign(n,false);
    while(!st.empty()){
        int u=st.top();st.pop();
        if(!vis[u]){
            count++;
            dfs(u,newg,st,vis,false);
        }
    }
    cout<<count;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        vc<vc<int>> g(a);
        for(int i=0;i<b;i++){
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
        }
        solve(g);
    }
    return 0;
}
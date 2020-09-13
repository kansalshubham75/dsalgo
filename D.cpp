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
void dfs(vc<vc<int>>& g,int u,vector<bool>& vis,int da,int l,unordered_set<int>& canVisit){
    vis[u]=1;
    if(l%da==0)canVisit.insert(u);
    for(int i:g[u]){
        if(!vis[i])dfs(g,i,vis,da,l+1,canVisit);
    }
}
void solve(){
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    a--;b--;
    vc<vc<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;cin>>u>>v;u--;v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    unordered_set<int> canGoa;
    unordered_set<int> canGob;
    vector<bool> vis(n,0);
    dfs(g,a,vis,da,0,canGoa);
    vis.assign(n,0);
    dfs(g,b,vis,db,0,canGob);
    vector<int> vis_(n,-1);
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,a});
    while(!q.empty()){
        pii rn=q.top();q.pop();
        vis_[rn.second]=rn.first;
        for(int v:g[rn.second]){
            if(vis_[v]==-1)q.push({rn.first+1,v});
        }
    }
    cout<<vis_[b]<<endl;
    if(vis_[b]==da){
        cout<<"Alice\n";return;
    }
    
    for(int u:canGob){
        if(canGoa.find(u)!=canGoa.end()){
            cout<<"Alice\n";
            return;
        }
    }
    cout<<"Bob\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
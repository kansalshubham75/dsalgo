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
void solve(){
    int n,m;
    cin>>n>>m;
    vc<vc<pii>> g(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    ll ans=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(pii(0,0));
    vector<bool> vis(n,0);
    while(!pq.empty()){
        pii rn=pq.top();pq.pop();
        int u=rn.second,w=rn.first;
        if(vis[u])continue;
        vis[u]=1;
        ans+=w;
        for(auto edge:g[u]){
            if(!vis[edge.first])pq.push({edge.second,edge.first});
        }
    }
    cout<<ans<<endl;
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
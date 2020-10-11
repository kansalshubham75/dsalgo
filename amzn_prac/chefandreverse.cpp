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
        int u,v;
        cin>>u>>v;
        if(u==v)continue;
        u--;v--;
        g[u].pb({v,0});
        g[v].pb({u,1});
    }
    if(n<2){
        cout<<0<<endl;
        return;
    }
    deque<pii> q;             //f=vtx,s=wt
    vc<bool> vis(n,0);
    q.push_back({0,0});
    vis[0]=1;
    while(!q.empty()){
        auto p=q.front();q.pop_front();
        int u=p.first;
        int w=p.second;
        if(vis[u])continue;
        if(u==n-1){
                cout<<w<<endl;return;
        }
        for(auto edge:g[u]){
            int v=edge.first,wt=edge.second;
            wt+=w;
            wt==w?q.push_front({v,wt}):q.push_back({v,wt});
        }
    }
    
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
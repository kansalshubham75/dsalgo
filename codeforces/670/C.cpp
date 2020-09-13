#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
// int c1=-1,c2=-1,s=1e6;
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
// int dfs(int u,vc<vc<int>>& g,vc<bool>& vis){
//     // cout<<u<<" ";
//     vis[u]=1;
//     int n=g.size();
//     int max_size=0;
//     int mysize=1;
//     for(int v:g[u]){
//         if(!vis[v]){
//             int subsize=dfs(v,g,vis);
//             max_size=max(max_size,subsize);
//             mysize+=subsize;
//         }
//     }
//     // cout<<mysize<<endl;
//     int extra=g.size()-mysize-1;
//     max_size=max(max_size,extra);
//     if(max_size<s){
//         s=max_size;
//         c1=u;
//     }else if(max_size==s){
//         c2=u;
//     }
//     return mysize;
// }
void solve(){
    int n;
    cin>>n;
    vc<vc<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> centroid;
    vector<int> sz(n+1);
    function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
    dfs(1, -1);
    // dfs(1,g,vis);
    if(centroid.size()==2){
        int c1=centroid[0],c2=centroid[1];
        int toCut;
        for(int i:g[c2]){
            if(i!=c1){
                toCut=i;break;
            }
        }
        cout<<c2<<" "<<toCut<<endl;
        cout<<c1<<" "<<toCut<<endl;
    }else{
        cout<<1<<" "<<g[1][0];
        cout<<endl<<1<<" "<<g[1][0]<<endl;
    }
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
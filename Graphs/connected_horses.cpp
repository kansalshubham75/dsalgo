// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/connected-horses-10/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
ll mod=1e9+7;
vc<ll> facts;
int n,m,s;
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
void calc_facts(){
    facts.resize(1e6+1,0);
    facts[0]=1;
    for(ll i=1;i<=1e6;i++){
        facts[i]=(i*facts[(int)i-1])%mod;
    }
}
vc<vc<int>> dir={{2,1},{2,-1},{-1,2},{1,2},{-2,1},{-2-1},{-1,-2},{1,-2}};
bool is_safe(int r,int c){
    return r>=0 && c>=0 && r<n && c<m;
}
void dfs(int i,int j,vc<vc<int>>& b,vc<vc<bool>>& vis){
    vis[i][j]=1;
    s++;
    for(auto& d:dir){
        int r=i+d[0];
        int c=j+d[1];
        if(is_safe(r,c) && b[r][c]==1 && !vis[r][c])
            dfs(r,c,b,vis);
    }
}
void solve(){
    int q;
    cin>>n>>m>>q;
    vc<vc<int>> b(n,vc<int>(m,0));
    vc<vc<bool>> vis(n,vc<bool>(m,false));
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        x--;y--;
        b[x][y]=1;
    }
    ll ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            s=0;
            if(b[i][j]==1 && !vis[i][j]){
                dfs(i,j,b,vis);
                ans=(ans*(facts[s]%mod))%mod;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    calc_facts();
    while(t--){
        solve();
    }
    return 0;
}
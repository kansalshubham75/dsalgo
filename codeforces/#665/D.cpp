#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int> 
#define pll pair<long long int,long long int>
#define ll long long
int mod = 1e9+7;
ll mul(ll val1,ll val2){
    return (val1*val2)%mod;
}
int dfs(vector<vector<int>>& g,int u,vector<ll>& vis,vector<ll>& ew,int par){
    vis[u]=1;
    for(int v:g[u]){
        if(vis[v]==0){
            int rec=dfs(g,v,vis,ew,u);
            ew.push_back(rec*(g.size()-rec)); 
            vis[u]+=rec;
        }
    }
    return vis[u];
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> e(n-1,vector<int>(2));
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        cin>>e[i][0]>>e[i][1];
        e[i][0]--;
        e[i][1]--;
        g[e[i][0]].pb(e[i][1]);
        g[e[i][1]].pb(e[i][0]);
    }
    int m;
    cin>>m;
    vector<ll> primes(m);
    for(int i=0;i<m;i++)
        cin>>primes[i];
    vector<ll> vis(n,0);
    vector<ll> ew;
    dfs(g,0,vis,ew,-1);
    sort(ew.begin(),ew.end(),greater<ll>());
    sort(primes.begin(),primes.end(),greater<ll>());   
    ll val=0;
    int i=0,j=0;
    if(m>(n-1)){
        ll extra=1;
        while(j<(m-n+2)){
            extra=mul(extra,primes[j]);
            j++;
        }
        val=(val+mul(ew[i],extra))%mod;
        i++;
    }
    while(j<m){
        val=(val+mul(primes[j],ew[i]))%mod;
        i++;
        j++;
    }
    while(i<n-1){
        val=(val+ew[i])%mod;
        i++;
    }
    cout<<val%mod<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
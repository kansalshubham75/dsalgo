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
ll calculateDist(vc<vc<ll>>& pts,int i,int j){
    ll ans=0,d=pts[0].size();
    for(int k=0;k<d;k++)ans+=abs(pts[i][k]-pts[j][k]);
    return ans;
}
void solve(){
    ll n,d;
    cin>>n>>d;
    vc<vc<ll>> pts(n,vc<ll>(d));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<d;j++)cin>>pts[i][j];
    }
    priority_queue<pll,vc<pll>,greater<pll>> pq;
    ll ans=0;
    pq.push({0,0});
    set<int> vis;
    for(int i=0;i<n;i++)vis.insert(i);
    int done=0;
    while(!pq.empty() && done<n){
        pll rn=pq.top();pq.pop();
        if(vis.find(rn.second)==vis.end())continue;
        vis.erase(rn.second);
        done++;
        ans+=rn.first;
        for(auto i:vis){
            ll dist=calculateDist(pts,rn.second,i);
            pq.push({-dist,i});
        }
    }
    cout<<-ans<<endl;
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
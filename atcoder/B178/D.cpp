#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
ll mod=1e9+7;
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}

void solve(){
    int max_=0;
    int n;
    cin>>n;
    unordered_set<string> s;
    vc<pii> pts(n);
    for(int i=0;i<n;i++){
        cin>>pts[i].first>>pts[i].second;
        s.insert(to_string(pts[i].first)+"_"+to_string(pts[i].second));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            max_=max(max_,(abs(pts[i].first-pts[j].first)+abs(pts[i].second-pts[j].second)));
        }
    }
    cout<<max_;
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
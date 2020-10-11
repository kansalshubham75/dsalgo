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
    ll a,b,c;
    cin>>a>>b>>c;
    ll max_=max(a,max(b,c));
    ll min_=min(a,min(b,c));
    ll smin=a+b-max_+c;
    ll ans=sqrt((smin*smin)+(max_*max_));
    cout<<ans<<endl;
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
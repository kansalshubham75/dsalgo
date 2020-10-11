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
    int n;
    cin>>n;
    map<ll,int> m;
    ll p=0,ans=0;
    m[0]=1;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p+=x;
        if(m.count(p)){
            ans++;
            m.clear();
            m[0]=1;
            p=x;
        }
        m[p]++;
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
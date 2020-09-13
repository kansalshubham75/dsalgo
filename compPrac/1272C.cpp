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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    unordered_set<char> m;
    for(int i=0;i<k;i++){
        char x;
        cin>>x;
        m.insert(x);
    }
    int j=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        if(m.find(s[i])==m.end()){
            j=i+1;
            continue;
        }
        ans+=(i-j+1);
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
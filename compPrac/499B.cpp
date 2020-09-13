#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    unordered_map<string,string> map_;
    for(int i=0;i<m;i++){
        string f,s;
        cin>>f>>s;
        map_[f]=f.length()<=s.length()?f:s;
    }
    for(int i=0;i<n;i++){
        string l;
        cin>>l;
        cout<<map_[l]<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
        solve();
    return 0;
}
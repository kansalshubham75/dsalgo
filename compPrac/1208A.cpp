#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    vector<int> ans(3);
    cin>>ans[0]>>ans[1]>>n;
    ans[2]=ans[1]^ans[0];
    cout<<ans[n%3]<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
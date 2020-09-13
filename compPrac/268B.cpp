#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=(1+(i*(n-i)));
    }
    cout<<ans<<endl;
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
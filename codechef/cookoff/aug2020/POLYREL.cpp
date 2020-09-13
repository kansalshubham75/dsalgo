#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int x,y;
    // for(int i=0;i<n;i++)
    //     cin>>x>>y;
    int ans=n;
    while(n>5){
        n/=2;
        ans+=n;
    }
    cout<<ans<<endl;
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
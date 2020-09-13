#include <bits/stdc++.h>
using namespace std;
void solve(){
    int pc,pr;
    cin>>pc>>pr;
    int nc,nr;
    nc=(pc/9)+(pc%9>0);
    nr=(pr/9)+(pr%9>0);
    int ans=nc<nr?0:1;
    cout<<ans<<" "<<min(nc,nr)<<endl;
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
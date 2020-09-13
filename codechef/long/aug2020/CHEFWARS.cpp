#include <bits/stdc++.h>
using namespace std;
void solve(){
    int h,p;
    cin>>h>>p;
    while(h>0 && p>0){
        h-=p;
        p/=2;
    }
    int ans=h>0?0:1;
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
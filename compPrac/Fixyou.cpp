#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    long long ans=0;
    for(int i=0;i<n;i++){
            string c;
            cin>>c;
            if(c[c.size()-1]=='R'){
                ans++;
            }
            if(i==n-1){
                for(int j=0;j<m;j++){
                    if(c[j]=='D')
                        ans++;
                }
            }
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
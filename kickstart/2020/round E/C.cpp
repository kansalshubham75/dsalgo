#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void solve(){
    int n;
    cin>>n;
    vc<int> e(n);
    vc<int> r(n);
    for(int i=0;i<n;i++){
        cin>>e[i]>>r[i];
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}


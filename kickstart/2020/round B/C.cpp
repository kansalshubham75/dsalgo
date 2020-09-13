#include <bits/stdc++.h>
using namespace std;
void solve(){
    unordered_map<char,pair<int,int>> m;
    m['N']={0,-1};
    m['S']={0,1};
    m['E']={1,0};
    m['W']={-1,0};
    
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
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int moves=INT_MAX,player=-1;
    for(int i=0;i<n;i++){
        int pi;
        cin>>pi;
        if(pi<=k && ((k-pi)%pi)==0){
            int moves_=(k-pi)/pi;
            if(moves_<moves){
                moves=moves_;
                player=pi;
            }
        }
    }
    cout<<player<<endl;
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
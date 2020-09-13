#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
void solve(){
    int z,o;
    cin>>z>>o;
    if((z>o && z-o>1) || (o>(2*z+2))){
        cout<<-1;
        return ;
    }
    if(o>z){
        int extra=o-(z+1);
        o-=extra;
        for(int i=0;i<o;i++){
            cout<<1;
            if(extra){
                cout<<1;extra--;
            }
            if(z){
                cout<<0;
                z--;
            }
        }
    }else{
        for(int i=0;i<z;i++){
            cout<<0;
            if(o){
                cout<<1;o--;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
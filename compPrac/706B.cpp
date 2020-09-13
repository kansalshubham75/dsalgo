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
    int n,q;
    cin>>n;
    vector<int> prices(1e5+1,0);
    for(int i=0;i<n;i++){
        int price;
        cin>>price;
        prices[price]++;
    }
    for(int i=1;i<prices.size();i++){
        prices[i]+=prices[i-1];
    }
    cin>>q;
    for(int i=0;i<q;i++){
        int coins;
        cin>>coins;
        coins=min(coins,(int)1e5);
        cout<<prices[coins]<<endl;
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
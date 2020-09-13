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
    int n;
    cin>>n;
    vector<int> arr(n);
    read(arr);
    int lmap[n+1];
    ll ans=0;
    memset(lmap,0,sizeof(lmap));
    for(int i=0;i<n;i++){
        int rmap[n+1];
        memset(rmap,0,sizeof(rmap));
        for(int j=n-1;j>i;j--){
            ans+=(rmap[arr[i]]*lmap[arr[j]]);
            rmap[arr[j]]++;
        }
        lmap[arr[i]]++;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
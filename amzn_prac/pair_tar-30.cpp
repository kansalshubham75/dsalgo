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
    vector<int> arr={20, 50, 40, 25, 30, 10};
    int tar=60;
    unordered_map<int,int> seen;
    vector<int> ans={-1,-1,INT_MIN};
    for(int i=0;i<arr.size();i++){
        if(seen.find(tar-arr[i])!=seen.end()){
            int max_=max(tar-arr[i],arr[i]);
            if(ans[2]<max_)ans={seen[tar-arr[i]],i,max_};
        }
        seen[arr[i]]=i;
    }
    cout<<ans[0]<<" "<<ans[1];
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
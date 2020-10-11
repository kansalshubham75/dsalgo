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
    vc<int> arr={1, 5, 1, 5};
    int tar=6,cnt=0;
    unordered_set<int> seen;
    unordered_set<int> taken;
    for(int i=0;i<arr.size();i++){
        int complement=tar-arr[i];
        if(seen.count(complement) && !taken.count(arr[i]) && !taken.count(complement)){
            cnt++;
            taken.insert(arr[i]);
        }
        seen.insert(arr[i]);
    }
    cout<<cnt;
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
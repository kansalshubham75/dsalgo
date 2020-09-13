#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    int ans=0,curr=0;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]>k){
            cout<<-1<<endl;
            return;
        }
    }
    int i=0;
    while(i<n){
        if(curr+arr[i]<=k){
            curr+=arr[i];
        }else{
            ans++;
            curr=arr[i];
        }
        i++;
    }
    if(curr>0)
        ans++;
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
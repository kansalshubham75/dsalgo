#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr[i]={x,i};
    }
    int ans=0;
    sort(arr.begin(),arr.end());
    for(int i=n-1;i>=0;i--){
        ans+=(((n-i-1)*arr[i].first)+1);
    }
    cout<<ans;
    cout<<endl;
    for(int i=n-1;i>=0;i--)
        cout<<arr[i].second+1<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
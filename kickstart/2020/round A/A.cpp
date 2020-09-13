#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,b;
    cin>>n>>b;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    sort(arr.begin(),arr.end());
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=b){
            b-=arr[i];
            count++;
        }
    }
    cout<<count<<endl;
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
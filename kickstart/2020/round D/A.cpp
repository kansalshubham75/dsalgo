#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int min_=-1,count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>min_ && ((i+1<n && arr[i]>arr[i+1]) || i==n-1)){
            count++;
        }
        min_=max(min_,arr[i]);
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
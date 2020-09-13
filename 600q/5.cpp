#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i+=2){
        if(arr[i]<arr[i-1])
            swap(arr[i],arr[i-1]);
        if(i+1<n && arr[i]<arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    for(int& i:arr)
        cout<<i<<" ";
    cout<<endl;
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
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> dep(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cin>>dep[i];
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    int i=0,j=0,curr=0,max_=0;
    while(i<n && j<n){
        if(arr[i]<=dep[j]){
            curr++;
            i++;
        }else{
            curr--;
            j++;
        }
        max_=max(max_,curr);
    }
    cout<<max_<<endl;
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
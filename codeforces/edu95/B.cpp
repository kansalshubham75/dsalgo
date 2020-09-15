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
    int arr[n];
    bool unlocked[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0;i<n;i++)cin>>unlocked[i];
    vector<int> uVals;
    for(int i=0;i<n;i++){
        if(!unlocked[i])uVals.pb(arr[i]);
    }
    sort(uVals.begin(),uVals.end());

    if(sum<0){
        for(int i=0;i<n;i++)cout<<arr[i]<<" ";
        cout<<endl;return;
    }else if(sum>=0){
        reverse(uVals.begin(),uVals.end());
        int j=0;
        for(int i=0;i<n;i++){
            if(!unlocked[i]){
                arr[i]=uVals[j];
                j++;
            }
        }
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
    cout<<endl;

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
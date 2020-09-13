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
    // priority_queue<int> maxpq;
    // priority_queue<int,vc<int>,greater<int>> minpq;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
        
    // }
    vc<int> arr(n);
    read(arr);
    ll ans=LLONG_MIN;
    sort(arr.begin(),arr.end());
    for(int i=0;i<=5;i++){
        int fromend=5-i;
        ll prod=1;
        int j=n-1;
        while(fromend--){
            prod*=arr[j];j--;
        }
        j=0;
        while(j<i){
            prod*=arr[j];j++;
        }
        ans=max(ans,prod);
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
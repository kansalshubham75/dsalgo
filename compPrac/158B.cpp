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
    vc<int> arr(n);
    read(arr);
    sort(arr.begin(),arr.end());
    int i=0,j=n-1,ans=0;
    while(i<j){
        ans++;
        int left=4-arr[j];
        while(i<j && left-arr[i]>=0)
            left-=arr[i++];
        j--;
    }
    if(i==j)
        ans++;
    cout<<ans<<endl;
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
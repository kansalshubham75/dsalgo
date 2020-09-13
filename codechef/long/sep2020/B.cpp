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
    vc<vc<int>> arr(n,vc<int>(n));
    for(int i=0;i<n;i++)read(arr[i]);
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[0][i]!=i+1){
            if(i-1<1)ans++;
            else if(arr[0][i-1]==i)ans+=2;
        }
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
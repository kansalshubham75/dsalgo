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
    vc<int> arr={0,0,1,0,0,1,0,0,0};
    int n=arr.size();
    int oc_0=0,oc_1=0;
    for(int i=0;i<n;i++){
        int temp=oc_0;
        oc_0+=arr[i]==0?0:1;
        oc_1=min(temp,oc_1)+(arr[i]==0?1:0);
    }
    cout<<min(oc_0,oc_1);
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
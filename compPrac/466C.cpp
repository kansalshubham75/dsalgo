// https://codeforces.com/problemset/problem/466/C
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
    ll sum=0;
    for(int i:arr)sum+=i;
    if(sum%3!=0){
        cout<<0<<endl;
        return;
    }
    sum/=3;
    ll ct=0,res=0,curr=0;
    for(int i=0;i<n-1;i++){
        curr+=arr[i];
        if(curr==2*sum){
            res+=ct;
        }
        if(curr==sum){
            ct++;
        }
    }
    cout<<res<<endl;
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
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
    int n=12;
    int curr=0,jump=1;
    while(curr<n){
        curr+=jump;
        jump++;
    }
    int diff=curr-n;
    if(diff%2==0){
        cout<<jump-1;
    }else{
        if(jump%2)cout<<jump;
        else cout<<jump+1;
    }
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
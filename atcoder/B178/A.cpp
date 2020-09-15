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
int n=1e6+10;
void solve(){
    ll fact[n];
    fact[0]=1;
    for(int i=0;i<n;i++)fact[i]=i*fact[i-1];
    int N;
    cin>>N;
    if(N<2){
        cout<<0;return;
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
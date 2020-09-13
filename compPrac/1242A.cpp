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
int isPrime(int n){
    int prev=1;
    for(int i=2;i*i<n;i++){
        if((n%i)==0)  prev=i;
    }
    return prev;
}
void solve(){
    int n;
    cin>>n;
    if((n%2)==0){
        cout<<(n/2);
        return;
    }
    int val=isPrime(n);
    val=val==1?n:val;
    cout<<val;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
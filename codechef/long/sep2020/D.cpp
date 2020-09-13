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
    ll n;
    cin>>n;
    ll sum=(1LL*n*(n+1))/2;
    // cout<<sum<<endl;
    if(sum%2){
        cout<<0<<endl;return;
    }
    sum=sum/2;
    // cout<<sum<<endl;
    ll small=1;
    ll temp=0;
    while(temp+small<=sum){
        temp+=small;
        small++;
    }
    // cout<<small<<endl;
    small--;
    ll sumSmall=temp;
    // cout<<sumSmall<<endl;
    if(sumSmall==sum){
        ll smallswap=(small*(small-1))/2;
        ll big=n-small;
        ll bigSwap=(big*(big-1))/2;
        ll ans=smallswap+bigSwap;
        if(big==1)ans++;
        cout<<ans<<endl;return;
    }
    ll diff=sum-sumSmall;
    ll swaps=min(n-diff,small)-(small-diff+1)+1;
    if(swaps<0) swaps=0;
    cout<<swaps<<endl;
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
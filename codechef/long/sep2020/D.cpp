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
    if(sum%2){
        cout<<0<<endl;return;
    }
    sum=sum/2;
    ll smaller=0,small_size=0;
    for(int i=1;i<n;i++){
        if(smaller+i>sum)break;
        small_size=i;
        smaller+=i;
    }
    // cout<<smaller<<" "<<small_size<<endl;
    ll diff=sum-smaller;
    ll swaps=0;
    if(diff==0){
        ll small_swaps=(small_size*(small_size-1))/2;
        ll large_size=n-small_size;
        ll large_swaps=(large_size*(large_size-1))/2;
        swaps=small_swaps+large_swaps;
        if(large_size==1)swaps++;
    }else{
        for(ll i=1;i<=small_size;i++){
            if(i+diff>small_size && i+diff<=n)  swaps++;
        }
    }
    cout<<swaps<<endl;
    
    // if(diff==0){
        
    // }else{
    //     int min_ele=max(small_size-diff+1,0LL);
    //     int max_ele=min(n,small_size+diff);
    // }
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
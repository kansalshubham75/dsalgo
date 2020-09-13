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
    int s;
    cin>>n>>s;
    ll temp=n;
    int sum=0;
    vc<int> arr(18,0);
    int i=17;
    while(temp!=0){
        arr[i--]=temp%10;
        temp/=10;
    }
    for(int i:arr)sum+=i;
    i=17;
    vc<int> ans(18,0);
    while(i>=0  && sum>s){
        if(arr[i]==0){
            i--;
            continue;
        }
        sum=sum-arr[i]+1;
        ans[i]=10-arr[i];
        arr[i]=0;
        if(i-1>=0)arr[i-1]++;
        i--;
    }
    i=0;
    while(i<18 && ans[i]==0)i++;
    if(i==18)cout<<0;
    for(;i<18;i++)cout<<ans[i];
    cout<<endl;
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
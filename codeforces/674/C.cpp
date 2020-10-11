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
    int ans=0;
    int curr=1;
    int app=n;
    int lo=1,hi=n;
    while(lo<hi){
        int mid=lo+((hi-lo)/2);
        int moves=mid-1+((n-mid)/mid);
        if(moves<app){
            app=moves;
            hi=mid;
        }else{
            lo=mid;
        }
    }
    cout<<lo<<endl;
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
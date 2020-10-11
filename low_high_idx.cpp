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
int b_search(vc<int>& arr,int val){
    int lo=0,hi=arr.size()-1;
    while(lo<hi){
        int mid=lo+((hi-lo)/2);

        if(arr[mid]<val){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    return lo;
}
void solve(){
    vc<int> arr={1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5};
    cout<<"lo : "<<b_search(arr,5)<<endl;
    int hi=b_search(arr,6);
    hi=arr[hi]>5?hi-1:hi;
    cout<<"hi : "<<hi;
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
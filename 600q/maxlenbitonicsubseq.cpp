#include <bits/stdc++.h>
using namespace std;
int findIndex(vector<int>& l,int val){
    int lo=0,hi=l.size()-1;
    while(lo<hi){
        int mid=lo+((hi-lo)/2);
        if(l[mid]<val)
            lo=mid+1;
        else
            hi=mid;
    }
    return lo;
}
void lis(vector<int>& arr,vector<int>& ans){
    vector<int> l(arr.size()+1,INT_MAX);
    l[0]=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int idx=findIndex(l,arr[i]);
        l[idx]=arr[i];
        ans[i]=idx;
    }
    // for(int i:ans)
    //     cout<<i<<" ";
    // cout<<endl;
}
void lds(vector<int>& arr,vector<int>& ans){
    vector<int> l(arr.size()+1,INT_MAX);
    l[0]=INT_MIN;
    for(int i=arr.size()-1;i>=0;i--){
        int idx=findIndex(l,arr[i]);
        l[idx]=arr[i];
        ans[i]=idx;
    }
    for(int i:ans)
        cout<<i<<" ";
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    vector<int> incSub(n);
    vector<int> decSub(n);
    lis(arr,incSub);
    lds(arr,decSub);
    int max_=0;
    for(int i=0;i<n;i++){
        max_=max(max_,incSub[i]+decSub[i]-1);
    }
    cout<<max_<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
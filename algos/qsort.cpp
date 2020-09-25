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
int partition(vector<int>& arr,int lo,int hi){
    int ele=arr[hi];
    int i=0,j=hi-1;
    while(i<j){
        if(arr[i]>=ele && arr[j]<ele){
            swap(arr[i],arr[j]);
        }else if(arr[j]>=ele){
            j--;
        }else if(arr[i]<ele){
            i++;
        }
    }
    if(arr[i]>=ele)swap(arr[i],arr[hi]);
    else swap(arr[++i],arr[hi]);
    return i;
}
void qsort(vc<int>& arr,int lo,int hi){
    if(lo>=hi)return;
    int pivot=partition(arr,lo,hi);
    qsort(arr,lo,pivot-1);
    qsort(arr,pivot+1,hi);
}
void solve(){
    vc<int> arr={5,1,6,7,8,11,4,5,1,54,33,43,2};
    qsort(arr,0,arr.size()-1);
    for(int i:arr)cout<<i<<" ";
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
#include <bits/stdc++.h>
using namespace std;
//vecrsion 1 : 2 binary search -> 1 for pivot and 1 to search t 
void solve(){
    int n,t;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>t;
    int lo=0,hi=n-1;
    while(lo<hi){
        int mid=lo+((hi-lo)/2);
        if(arr[mid]<arr[hi])
            hi=mid;
        else
            lo=mid+1;
    }
    int pivot=hi;
    if(t<=arr[n-1]){
        lo=pivot;
        hi=n-1;
    }else{
        lo=0;
        hi=pivot-1;
    }
    // cout<<lo<<" "<<hi;
    while(lo<hi){
        int mid=lo+((hi-lo)/2);
        if(arr[mid]<t)
            lo=mid+1;
        else
            hi=mid;
    }
    if(arr[lo]==t)
        cout<<lo<<endl;
    else
        cout<<-1<<endl;
}
//version 2 : single binary search
void solve2(){
    int n,t;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cin>>t;
    int lo=0,hi=n-1;
    while(lo<hi){
        int mid=lo+((hi-lo)/2);
        if(arr[mid]==t){ 
            cout<<mid<<endl;
            return;
        }else if(arr[lo]<arr[mid]){         //if arr[lo]....arr[mid] is sorted
            if(t>=arr[lo] && t<arr[mid])       //if target lies in range[lo....mid]
                hi=mid-1;                      //then search in [lo.....mid]
            else                                //else  recur for [mid+1....hi]
                lo=mid+1;
        }else{                               //if [lo....mid] is not sorted then [mid....hi] must be sorted
            if(t>arr[mid] && t<=arr[hi])     
                lo=mid+1;
            else
                hi=mid-1;
        }
    }
    if(arr[lo]==t)
        cout<<lo<<endl;
    else
        cout<<-1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve2();
    return 0;
}
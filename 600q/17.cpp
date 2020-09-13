#include <bits/stdc++.h>
using namespace std;
vector<int> threeWayPartition(vector<int>& arr, int lo, int hi){
    int n=arr.size();
    int i=0,j=0,k=n-1;
    while(i<n && arr[i]<lo)
        i++;
    while(k>i && arr[k]>hi)
        k--;
    j=i;
    while(j<=k){
        if(arr[j]<lo){
            swap(arr[j],arr[i]);
            i++;
            j++;
        }else if(arr[j]>hi){
            swap(arr[j],arr[k]);
            k--;
        }else{
            j++;
        }
    }
    for(int i:arr)
        cout<<i<<" ";
}
void solve(){
    vector<int> arr={1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32} ;
    threeWayPartition(arr,14,20);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
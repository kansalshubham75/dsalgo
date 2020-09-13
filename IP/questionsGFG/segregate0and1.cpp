#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void solve(vector<int>& arr){
    int i=0,j=0;
    while(arr[i]!=1 && i<arr.size())
        i++;
    j=i+1;
    while(j<arr.size()){
        if(arr[j]==0){
            swap(arr[i],arr[j]);
            i++;
            j++;
        }else{
            j++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        solve(arr);
    }
    return 0;
}
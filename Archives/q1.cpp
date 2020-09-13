//https://www.geeksforgeeks.org/minimum-cost-of-reducing-array-by-merging-any-adjacent-elements-repetitively/
#include <bits/stdc++.h>
using namespace std;
void swap_(int& a1,int& a2){
    int temp=a1;
    a1=a2;
    a2=temp;
}
void arrange(vector<int>& arr, int n) {
    // Your code here
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i])
            continue;
        int curr=i;
        int idx=arr[i];
        while(idx!=i){
            vis[curr]=vis[idx]=1;
            swap(arr[curr],arr[idx]);
            int temp=abs(arr[curr]);
            curr=idx;
            idx=temp;
        }
    }
    // for(int i=0;i<n;i++)
    //     arr[i]=abs(arr[i]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr={4,0,2,1,3};
    arrange(arr,5);
    for(int i:arr)
        cout<<i<<" ";
    return 0;
}
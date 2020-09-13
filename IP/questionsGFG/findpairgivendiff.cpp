#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            arr.push_back(a);
        }
        sort(arr.begin(),arr.end());
        int i=0,j=0,found=-1;
        while(i<n){
            int diff=abs(arr[i]-arr[j]);
            if(diff==x){
                found=1;
                break;
            }else if(diff<x)
                i++;
            else
                j++;
        }
        cout<<found<<endl;
    }
    return 0;
}
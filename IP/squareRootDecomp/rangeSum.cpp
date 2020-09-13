#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

vector<int> preprocess(vector<int>& arr){
    int n=ceil(sqrt(arr.size()));
    
    vector<int> pre(n,0);

    for(int i=0;i<arr.size();i++){
        int idx=i/n;
        pre[idx]+=arr[i];
    }
    return pre;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> rootnarr=preprocess(arr);

    for(int i:rootnarr)
        cout<<i<<" ";
    cout<<endl;
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int sum=0;
        while(l<=r){
            if(l%rootnarr.size()==0 && l+rootnarr.size()<=r){
                int idx=l/rootnarr.size();
                sum+=rootnarr[idx];
                cout<<rootnarr[idx]<<" ";
                l+=rootnarr.size();
            }else{
                sum+=arr[l];
                cout<<arr[l]<<" ";
                l++;
            }
        }
        cout<<endl<<sum<<endl;
    }
    return 0;
}
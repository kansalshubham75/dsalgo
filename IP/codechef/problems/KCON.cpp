#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

ll kadane(vector<int>& arr){
    ll cs=arr[0],os=arr[0];
    for(int i=1;i<arr.size();i++){
        if(cs>=0){
            cs+=arr[i];
        }else
        {
            cs=arr[i];
        }
        os=max(os,cs);
    }

    return os;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr;
        ll sum=0;
        for(int i=0;i<n;i++){
            int ele;
            cin>>ele;
            sum+=ele;
            arr.push_back(ele);
        }
        if(k==1){
            cout<<kadane(arr)<<endl;
            continue;
        }

        for(int i=0;i<n;i++){
            arr.push_back(arr[i]);
        }
        
        ll ans=kadane(arr);
        if(sum>=0){
            ans+=(k-2)*sum;
            cout<<ans<<endl;
        }else{
            cout<<ans<<endl;
        }  
	}
	return 0;
}

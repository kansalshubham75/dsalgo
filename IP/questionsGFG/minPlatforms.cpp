#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr,dep;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            dep.push_back(x);
        }

        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        int ans=-1,curr=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){   //(= because) new train comes but the old doesnt leave therefore platform count increases dont increment j as it will be done in the next iteration
                curr++;
                i++;
            }else{
                j++;
                curr--;
            }
            ans=max(ans,curr);
        }
    cout<<ans<<endl;
    }
    return 0;
}
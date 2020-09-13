#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        vector<int> osum(1,0);
        vector<int> esum(1,0);
        for(int i=0;i<arr.size();i++){
            if(i%2)
                osum.push_back(osum[osum.back()]+arr[i]);
            else
                esum.push_back(esum[esum.back()]+arr[i]);
        }
        if(osum.size()<esum.size())
            osum.push_back(0);
        
    }
    return 0;
}
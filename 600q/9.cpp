#include <iostream>
#include<vector>
using namespace std;
// /* Version 1 : O(n) time, O(n) space
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> lm(n);
    vector<int> rm(n);
    lm[0]=arr[0];
    rm[n-1]=arr[n-1];
    for(int i=1;i<n;i++)
        lm[i]=max(lm[i-1],arr[i]);
    for(int i=n-2;i>=0;i--)
        rm[i]=max(rm[i+1],arr[i]);
    int max_=0;
    for(int i=1;i<n-1;i++){
        if(lm[i-1]>arr[i] && rm[i+1]>arr[i])
        max_+=min(lm[i-1],rm[i])-arr[i];
    }
    cout<<max_<<endl;
}
// */
//Version 2: skip rm array and calculate water while iterating rm
/*Version 3: O(n) time, O(1) space
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0,j=n-1,lm=-1,rm=-1,ans=0;
    while(i<j){
        int val;
        if(arr[i]<arr[j]){
            val=lm-arr[i];
            if(val>0)
                ans+=val;
            lm=max(lm,arr[i]);
            i++;
        }else{
            val=rm-arr[j];
            if(val>0)
                ans+=val;
            rm=max(rm,arr[j]);
            j--;
        }
    }
    cout<<ans<<endl;
}
*/
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	    solve();
	return 0;
}
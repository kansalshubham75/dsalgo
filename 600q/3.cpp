#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,sum=0;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int leftsum=0;
    for(int i=0;i<n;i++){
        int rightsum=sum-(leftsum+arr[i]);
        if(rightsum==leftsum){
            cout<<i+1<<endl;
            return;
        }
        leftsum+=arr[i];
    }
    cout<<-1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
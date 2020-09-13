#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int i=0,dec=0,max_=0,j=1;
    while(j<n){
        if(arr[j]==arr[j-1]){
            dec=0;
            max_=max(max_,j-i);
            i=j;
            j++;
        }else if(arr[j]<arr[j-1]){
            dec=1;
            j++;
            max_=max(max_,j-i);
        }else{
            if(dec){
                i=j-1;
                j++;
                dec=0;
            }else{
                j++;
                max_=max(max_,j-i);
            }
        }
    }
    cout<<max_<<endl;
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
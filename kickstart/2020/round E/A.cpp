#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void solve(){
    int n;
    cin>>n;
    vc<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int curr=1,max_=1;
    vc<int> temp(n-1);
    for(int i=0;i<n-1;i++)
        temp[i]=arr[i]-arr[i+1];
    for(int i=1;i<n-1;i++){
        if(temp[i]==temp[i-1]){
            curr++;
        }else{
            curr=1;
        }
        max_=max(max_,curr);
    }
    cout<<max_+1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}
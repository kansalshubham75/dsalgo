#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
void solve(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<20;i++){
        int shiftval=pow(2,i);
        int mask=(1<<shiftval);
        cout<<1<<" "<<mask<<endl;
        int val;
        cin>>val;
        val&=mask;
        if(!val){
            ans|=mask;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
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
    vc<vc<int>> b(n,vc<int>(3));
    for(int i=0;i<n;i++)cin>>b[i][0]>>b[i][1]>>b[i][2];
    vc<vc<int>> ans;
    ans.pb({b[0][0],b[0][2]});
    for(int i=1;i<n;i++){
        if(b[i-1][2]>=b[i][2] && b[i-1][1]>=b[i][1]){
            b[i]=b[i-1];
            continue;
        }
        if(b[i][0]<=b[i-1][1]){
            if(b[i][2]==b[i-1][2])continue;
            int s=b[i-1][2]>b[i][2]?b[i-1][1]:b[i][0];
            ans.pb({s,b[i][2]});
        }else{
            ans.pb({b[i-1][1],0});
            ans.pb({b[i][0],b[i][2]});
        }
    }
    ans.pb({b[n-1][1],0});
    for(int i=0;i<ans.size();i++)cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
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
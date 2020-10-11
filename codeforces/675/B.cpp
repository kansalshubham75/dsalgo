#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<ll>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vc<ll> arr(n*m);
    ll sum=0;
    vc<vc<ll>> mat(n,vc<ll>(m));
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            arr[k++]=mat[i][j];
        }
    }
    ll temp=0;
    bool isOk=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            temp+=mat[i][j];
            if(j<(m/2)){
                int idx=m-1-j;
                if(mat[i][j]!=mat[i][idx])isOk=false;
            }
            if(i<n/2){
                int idx=n-1-i;
                if(mat[i][j]!=mat[idx][j])isOk=false;
            }
        }
    }
    if(isOk){
        cout<<0<<endl;return;
    }
    sort(arr.begin(),arr.end());
    // for(int i:arr)cout<<i<<" ";
    // cout<<endl;
    int idx=(m*n)/2;
    // ll med=arr[idx];
    ll med=(temp)/(n*m);
    for(int i:arr)sum+=abs(i-med);
    cout<<sum<<endl;
}
int main(){
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

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
    int n,k,x,y;
    cin>>n>>k>>x>>y;
    int vis[n]={0};
    while(vis[x]==0){
        vis[x]=1;
        x=(x+k)%n;
    }
    if(vis[y])cout<<"YES";
    else cout<<"NO";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
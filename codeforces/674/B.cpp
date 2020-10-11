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
    int n,m;
    cin>>n>>m;
    // cout<<n<<" "<<m<<endl;
    if(m%2){
        cout<<"NO";
        for(int i=0;i<n;i++){
            vector<vc<int>> mat(2,vc<int>(2));
            cin>>mat[0][0]>>mat[0][1]>>mat[1][0]>>mat[1][1];
            // if(mat[0][0]==mat[1][1] && mat[0][1]==mat[1][0])res=true;
        }
    }else{
        bool res=false;
        for(int i=0;i<n;i++){
            vector<vc<int>> mat(2,vc<int>(2));
            cin>>mat[0][0]>>mat[0][1]>>mat[1][0]>>mat[1][1];
            if(mat[0][1]==mat[1][0])res=true;
        }
        if(res)cout<<"YES";
        else    cout<<"NO";
    }
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
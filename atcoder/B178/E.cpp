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
    int min_=INT_MAX,max_=INT_MIN;
    int min2=INT_MAX,max2=INT_MIN;
    int n;
    cin>>n;
    int mxN=2e5+10;
    bool mat[mxN][mxN];
    memset(mat,0,sizeof(mat));
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(mat[x][y])continue;
        mat[x][y]=1;
        int val=abs(x)+abs(y);
        if(val<min_){
            min2=min_;
            min_=val;
        }else if(val<min2){
            min2=val;
        }
        if(val>max_){
            max2=max_;
            max_=val;
        }else if(val>max2){
            max2=val;
        }
    }
    int max_dist=
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
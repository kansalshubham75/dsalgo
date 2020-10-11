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
int max_rounds(int p1[],int p2[]){
    int ans=0;
    ans=ans+min(p1[0],p2[1])+min(p1[1],p2[2])+min(p1[2],p2[0]);
    return ans;
}

void solve(){
    int n;
    cin>>n;
    int a[3],b[3];
    cin>>a[0]>>a[1]>>a[2]>>b[0]>>b[1]>>b[2];
    int max_=max_rounds(a,b);
    int min_=n-min_rounds(b,a);
    cout<<min_<<" "<<max_;
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
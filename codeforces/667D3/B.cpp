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
    int a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    if(max(x,a-n)<max(y,b-n)){
        ll newa=max(x,a-n);
        n=max(0LL,n-(a-newa));
        ll newb=max(y,b-n);
        cout<<newa*newb<<endl;
    }else{
        ll newb=max(y,b-n);
        n=max(0LL,n-(b-newb));
        ll newa=max(x,a-n);
        cout<<newa*newb<<endl;
    }
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
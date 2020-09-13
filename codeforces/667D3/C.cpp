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
    int n,x,y;
    cin>>n>>x>>y;
    n-=2;
    if(n==0){
        cout<<x<<" "<<y<<endl;return;
    }
    int diff=y-x,i=n+1;
    while(diff%i!=0 && i>0)i--;
    int cd=diff/i;
    for(int j=1;j<i;j++){
        cout<<x+(cd*j)<<" ";
    }
    n=n-i+1;
    cout<<x<<" "<<y<<" ";
    i=1;
    while(i<=n && x-(i*cd)>0){
        cout<<x-(i*cd)<<" ";
        i++;
    }
    n=n-i+1;
    i=1;
    while(i<=n){
        cout<<y+(cd*i)<<" ";
        i++;
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
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
int c=0;
void solve(vector<int> arr){
    if(arr.size()==5){
        for(int i:arr)cout<<i<<" ";
        c++;
        cout<<endl;
        return;
    }
    for(int i=0;i<6;i++){
        arr.pb(i);
        solve(arr);
        arr.pop_back();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve({});
    cout<<c;
    return 0;
}
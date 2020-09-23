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
    multiset<int> s;
    vector<int> arr={1,2,3,4,5,6,7};
    int k=5;
    for(int i=0;i<arr.size();i++)s.insert(arr[i]);
    for(int i=0;i<k;i++){
        int small=*s.begin();
        s.erase(s.begin());
        int large=*prev(s.end());
        s.erase(prev(s.end()));
        cout<<small<<" "<<large<<endl;
        s.insert(2*small);
        s.insert(large/2);
    }
    int sum=0;
    for(auto i:s)sum+=i;
    cout<<sum<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
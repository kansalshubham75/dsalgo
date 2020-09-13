#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    unordered_set<int> s;
    for(int i=0;i<n;i++){
        int poss1=arr[i]+d;
        int poss2=arr[i]-d;
        if(s.find(poss1)!=s.end() || s.find(poss2)!=s.end()){
            cout<<1<<endl;
            return;
        }
        s.insert(arr[i]);
    }
    cout<<-1<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
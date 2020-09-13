#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    priority_queue<int> pq;
    for(int i=1;i<n;i++)
        pq.push(arr[i]-arr[i-1]);
    for(int i=0;i<k;i++){
        int sess=pq.top();
        pq.pop();
        int int1=sess/2;
        int int2=sess-int1;
        pq.push(int1);
        pq.push(int2);
    }
    cout<<pq.top()<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int c=1;
    while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    return 0;
}
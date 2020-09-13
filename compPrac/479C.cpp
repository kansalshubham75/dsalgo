#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void read(vector<pii>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i].first>>arr[i].second;
}
void solve(){
    int n;
    cin>>n;
    vc<pii> arr(n);
    read(arr);
    sort(arr.begin(),arr.end());
    bool secondsorted=true;
    int prevExam=min(arr[0].first,arr[0].second);
    for(int i=1;i<n;i++){
        int exam_day=INT_MAX;
        if(arr[i].first>=prevExam){
            exam_day=arr[i].first;
        }
        if(arr[i].second>=prevExam){
            exam_day=min(exam_day,arr[i].second);
        }
        prevExam=exam_day;
    }
    cout<<prevExam;
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
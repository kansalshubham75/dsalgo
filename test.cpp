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
double dist(vector<pair<double,double>>& arr,int p1,int p2){
    return sqrt(((arr[p1].first-arr[p1].first)*(arr[p1].first-arr[p1].first)) + 
                ((arr[p1].second-arr[p1].second)*(arr[p1].second-arr[p1].second)));
}
double brute(vector<pair<double,double>>& arr,int lo,int hi){
    double min_=INT_MAX;
    for(int i=lo;i<hi;i++){
        for(int j=i+1;j<=hi;j++){
            min_=min(min_,dist(arr,i,j));
        }
    }
    return min_;
}
double find_min(vector<pair<double,double>>& arr,int lo,int hi){
    if(hi-lo<=3)return brute(arr,lo,hi);
    int mid=lo+((hi-lo)/2);
    double l=find_min(arr,lo,mid);
    double r=find_min(arr,mid+1,hi);
    double min_dist=min(l,r);
    vector<pair<double,double>> strip;
    int mid_x=arr[mid].first;
    for(int i=lo;i<=hi;i++){
        // if(i==mid)continue;
        if(dist(arr,i,mid)<min_dist)strip.push_back(arr[i]);
    }
    sort(strip.begin(),strip.end());
    return min(min_dist,brute(strip,0,strip.size()-1));
}
void solve(){
    vector<pair<double,double>> arr={{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    cout<<find_min(arr,0,n-1);
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
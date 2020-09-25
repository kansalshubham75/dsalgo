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
void solve(vector<string>& cities,int n,vector<string>& que,vector<int>& x,vector<int>& y){
    unordered_map<string,pair<int,int>> m;
    unordered_map<int,map<int,string>> xvy;
    unordered_map<int,map<int,string>> yvx;
    for(int i=0;i<n;i++){
        m[cities[i]]={x[i],y[i]};
        xvy[x[i]][y[i]]=cities[i];
        yvx[y[i]][x[i]]=cities[i];
    }
    for(auto& q:que){
        pii co=m[cities[i]];
        int x_co=co.first;
        int y_co=co.second;
        if(xvy[x_co].size()==1 && yvx[y_co].size()==1){
            cout<<"None"<<endl;
            continue;
        }
        auto itx=xvy[x_co].find(y_co);
        auto ity=yvx[y_co].find(x_co);
        int d1=itx==xvy[x_co].begin()?INT_MAX:*prev(itx);

    }
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
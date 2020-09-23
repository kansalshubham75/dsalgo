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
    vc<vc<vc<int>>> schedule={{{1,3},{6,7},{11,15}},{{2,4},{17,18}},{{2,5},{9,12},{6,8}}};
    vc<vc<int>> merged;
    for(int i=0;i<schedule.size();i++){
        for(int j=0;j<schedule[i].size();j++)merged.pb(schedule[i][j]);
    }
    sort(merged.begin(),merged.end(),[](vc<int>& slot1,vector<int>& slot2){
        if(slot1[0]==slot2[0])return slot1[1]<slot2[1];
        return slot1[0]<slot2[0];
    });
    vector<vc<int>> res;
    res.pb(merged[0]);
    for(int i=1;i<merged.size();i++){
        if(merged[i][0]<=res.back()[1])res.back()[1]=max(res.back()[1],merged[i][1]);
        else res.pb(merged[i]);
    }
    for(auto& v:res)
    cout<<v[0]<<" "<<v[1]<<endl;
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
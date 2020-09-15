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
ll findSum(set<int>& m){
    ll ans=0;
    int i=1,j=m.size();
    for(auto val:m){
        if(i<j){
            ans+=val;
            i++;
        }
    }
    return ans;
}
int bSearch(vc<int>& co,int val){
    int lo=0,hi=co.size()-1;
    while(lo<hi){
        int mid=lo+((hi-lo+1)/2);
        if(co[mid]>=val){
            hi=mid-1;
        }else{
            lo=mid;
        }
    }
    return lo;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vc<int> co(n);
    for(int i=0;i<n;i++){
        cin>>co[i];
    }
    sort(co.begin(),co.end());
    set<int> m;
    for(int i=1;i<n;i++){
        m.insert(co[i]-co[i-1]);
    }
    cout<<findSum(m)<<endl;
    for(int i=0;i<q;i++){
        int t,x;
        cin>>t>>x;
        int idx=bSearch(co,x);
        // if(idx>0)m.erase(co[idx]-co[idx-1]);
        if(idx<n-1)m.erase(co[idx+1]-co[idx]);
        co.insert(co.begin()+idx+1,x);
        n=co.size();
        m.insert(co[idx+1]-co[idx]);
        if(idx+2<co.size())
        m.insert(co[idx+2]-co[idx+1]);
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
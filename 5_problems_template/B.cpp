#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
ll p=1e9+7;
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
class pair_{
    public:
    double wage;
    double quality;
    pair_(double w,double q){
        wage=w;
        quality=q;
    }
    bool operator<(pair_ const& p)const{
        double ratio=this->quality/p.quality;
        double w1=max(this->wage,ratio*p.wage);
        double w2=max(w2,this->wage/ratio);
        return w1>w2;
    }
};
void solve(){
    int n,k;
    cin>>n>>k;
    vc<pii> wq(n);
    for(int i=0;i<n;i++)cin>>wq[i].second;
    for(int i=0;i<n;i++)cin>>wq[i].first;
    priority_queue<pair_> pq;
    for(int i=0;i<n;i++){
        pq.push(pair_((double)wq[i].first,(double)wq[i].second));
        if(pq.size()>k)pq.pop();
    }
    vc<pair_> ans;
    while(!pq.empty()){
        ans.pb(pq.top());pq.pop();
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
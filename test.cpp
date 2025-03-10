#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
class pii{
    public:
    int first;
    int second;
    pii(int f,int s){
        first=f;
        second=s;
    }
    bool operator<(pii const& p1)const{
        return this->first > p1.second;
    }
};
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}

void solve(){
    priority_queue<pii> pq;
    pq.push(pii(5,0));
    pq.push(pii(2,1));
    cout<<pq.top().first;
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
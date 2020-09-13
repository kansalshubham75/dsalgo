// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/dhoom-4/
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
int solve(){
    int k,l;
    cin>>k>>l;
    int n;
    cin>>n;
    vc<int> keys(n);
    read(keys);
    queue<pair<int,int>> q;
    q.push({k,0});
    int m=100000;
    bool vis[100000];
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            int newval=(p.first*keys[i])%m;
            if(l==newval)   return p.second+1;
            if(!vis[newval]){
                vis[newval]=1;
                q.push({newval,p.second+1});
            }
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}
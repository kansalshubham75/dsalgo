#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int> 
#define pll pair<long long int,long long int>

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> outOfPlace(n);
    int min_=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        outOfPlace[i]=arr[i];
        min_=min(min_,arr[i]);
    }
    sort(outOfPlace.begin(),outOfPlace.end());
    for(int i=0;i<n;i++){
        if(outOfPlace[i]!=arr[i]){
            if(outOfPlace[i]%min_!=0){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
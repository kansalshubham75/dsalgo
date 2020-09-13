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
    int n;
    cin>>n;
    vc<int> arr(n);read(arr);
    sort(arr.begin(),arr.end());
    if(arr[0]>0){
        cout<<0<<endl;return;
    }
    if(n==1){
        if(arr[0]==0)cout<<1<<endl;
        else cout<<0<<endl;
        return;
    }
    vector<int> freq(101,0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int first=-1,second=-1;
    for(int i=0;i<freq.size();i++){
        if(freq[i]==1 && first==-1){
            first=i;
        }else if(freq[i]==0){
            if(first==-1){
                first=i;
            }
            second=i;
            break;
        }
    }
    cout<<first+second<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
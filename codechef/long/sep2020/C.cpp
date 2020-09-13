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
    vc<int> arr(n);
    read(arr);
    
}
// void solve(){
//     int n=5;
//     cin>>n;
//     vc<int> arr(n);
//     for(int i=0;i<n;i++)cin>>arr[i];
//     int min_=n,max_=0;
//     for(int i=0;i<n;i++){
//         unordered_set<int> s;
//         s.insert(i);
//         for(int t=0;t<5;t++){
//             for(int j=0;j<n;j++){
//                 int posj=j+(arr[j]*t);
//                 for(int inf:s){
//                     int posinf=inf+(t*arr[inf]);
//                     if(posj==posinf)s.insert(j);
//                 }
//             }
//         }
//         int size=(int)s.size();
//         min_=min(min_,size);
//         max_=max(max_,size);
//     }
//     cout<<min_<<" "<<max_<<endl;
// }
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
//https://codeforces.com/problemset/problem/489/C
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
    int m,s;
    cin>>m>>s;
    if((s==0 && m>1) || m*9<s){
        cout<<-1<<" "<<-1;
        return ;
    }
    if(s==0){
        cout<<0<<" "<<0;return ;
    }
    int max_[m],min_[m];
    memset(min_,0,sizeof(min_));
    memset(max_,0,sizeof(max_));
    int min_sum=0,max_sum=0;
    for(int i=0;i<m;i++){
        for(int digit=0;digit<10;digit++){
            if(i==0 && digit==0)continue;
            if((s-min_sum-digit)<=((m-i-1)*9)){
               min_[i]=digit;
               min_sum+=digit;
               break; 
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int digit=9;digit>=0;digit--){
            if((s-max_sum-digit)>=0){
               max_[i]=digit;
               max_sum+=digit;
               break; 
            }
        }
    }
    for(int i=0;i<m;i++)    cout<<min_[i];
    cout<<" ";
    for(int i=0;i<m;i++)    cout<<max_[i];
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
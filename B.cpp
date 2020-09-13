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
    ll neg=0,pos=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x<0){
            if(pos>0){
                pos=pos+x;
                if(pos<0){
                    neg+=pos;
                    pos=0;
                }
            }else{
                neg+=x;
            }
        }else{
            pos+=x;
        }
    }
    cout<<pos<<endl;
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
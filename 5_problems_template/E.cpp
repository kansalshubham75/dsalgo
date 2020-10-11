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
    string s1,s2;
    cin>>s1>>s2;
    int fact[11];
    fact[0]=1;
    for(int i=1;i<11;i++)fact[i]=fact[i-1]*i;
    int org=0;
    for(char c:s1)org+=c=='+'?1:-1;
    int q=0,curr=0;
    for(char c:s2){
        if(c=='?')q++;
        else  curr+=c=='+'?1:-1;
    }

    int diff=abs(curr-org);
    double ans=0;
    // cout<<diff<<endl;
    if(diff<=q){
        double totalways=pow(2,q);
        int plus=diff;
        if((q-diff)%2==0){
            plus+=((q-diff)/2);
            int minus=q-plus;
            // cout<<plus<<" "<<minus<<endl;
            // cout<<fact[q]<<" "<<fact[plus]<<" "<<fact[minus]<<endl;
            double fav=fact[q]/(fact[plus]*fact[minus]);
            if(minus==0)fav=1;
            // cout<<fav<<endl;
            ans=fav/totalways;
        }
    }
    cout<<setprecision(10)<<ans<<endl;
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
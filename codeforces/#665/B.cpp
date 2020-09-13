#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define pii pair<int,int> 
#define pll pair<long long int,long long int>
void solve(){
    ll a0,a1,a2,b0,b1,b2;
    cin>>a0>>a1>>a2>>b0>>b1>>b2;
    ll sum=0;
    ll good=min(a2,b1);
    sum+=(2*good);
    a2-=good;
    b1-=good;
    a1-=(b1+b0);
    if(a1>0){
        sum-=(a1*2);
    }
    cout<<sum<<endl;
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
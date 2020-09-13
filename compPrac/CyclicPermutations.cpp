#include <bits/stdc++.h>
using namespace std;
#define mxN 1000001
#define ll long long
ll m=1000000007;
void solve(){
    ll n;
    cin>>n;
    cout<<(1<<(n-1))%m<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
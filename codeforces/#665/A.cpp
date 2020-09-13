#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int> 
#define pll pair<long long int,long long int>
void solve(){
    int n,k;
    cin>>n>>k;
    if(k>n){
        cout<<k-n<<endl;
    }else{
        if((n%2==1 && k%2==0) || (n%2==0 && k%2==1))
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
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
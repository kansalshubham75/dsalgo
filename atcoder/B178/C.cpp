#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
int nCrModpDP(int n, int r) 
{ 
    int p=1e9+7;
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
void solve(){
    int n;
    cin>>n;
    if(n<2){
        cout<<0<<endl;
        return;
    }
    int fact[n+1];
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=i*fact[i-1];
    int mod=1e9+7,ans=1;
    for(int i=0;i<n-2;i++)ans=(1LL*ans*10)%mod;
    ans=(1LL*ans*fact[n])%mod;
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
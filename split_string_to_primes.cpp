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
int string_to_int(string& s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        ans=(ans*10)+(s[i]-'0');
    }
    return ans;
}
void solve(){
    vector<bool> primes(1e6+1,true);
    primes[0]=primes[1]=0;
    for(int i=2;i*i<=1e6;i++){
        if(primes[i]){
            for(int j=2*i;j<=1e6;j+=i)primes[j]=0;
        }
    }
    string s="11373";
    int n=s.length();
    vector<int> dp(n+1,0);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int cut=0;cut<6 && i+cut<n;cut++){
            string sub=s.substr(i,cut+1);
            int num=string_to_int(sub);
            if(primes[num] && dp[i+cut+1])dp[i]+=dp[i+cut+1];
        }
    }
    cout<<dp[0];
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
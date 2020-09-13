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
    string s;
    cin>>s;
    int ans=0;
    s+="R";
    vector<char> c(n);
    c[0]=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==c[i-1]){
            ans++;
            if(s[i]=='R'){
                c[i]=(s[i+1]=='R'?'G':(s[i+1]=='G'?'B':'G'));
            }
            if(s[i]=='G'){
                c[i]=(s[i+1]=='G'?'R':(s[i+1]=='R'?'B':'R'));
            }
            if(s[i]=='B'){
                c[i]=(s[i+1]=='B'?'G':(s[i+1]=='G'?'R':'G'));
            }
        }else{
            c[i]=s[i];
        }
    }
    cout<<ans<<"\n";
    for(char ch:c)cout<<ch;
    cout<<endl;
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
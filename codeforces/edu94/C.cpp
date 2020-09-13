#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
void solve(){
    string s;
    cin>>s;
    int x;
    cin>>x;
    int n=s.length();
    char ans[n];
    for(int i=0;i<n;i++)
        ans[i]='1';
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            if(i-x>=0)
                ans[i-x]='0';
            if(i+x<n)
                ans[i+x]='0';
        }
    }
    bool canForm=true;
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            if((i-x<0 || ans[i-x]=='0') && (i+x>=n || ans[i+x]=='0')){
                canForm=false;
            }
        }
    }
    if(!canForm){
        cout<<-1;
    }else{
        for(int i=0;i<n;i++)
            cout<<ans[i];
    }
    cout<<endl;
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
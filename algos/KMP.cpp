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
    string s,p;
    cin>>s>>p;
    int n=s.length(),m=p.length();
    if(n<m || n==0 || m==0){
        cout<<"Not Found";
        cout<<endl<<endl;
    }
    int lps[n];
    memset(lps,0,sizeof(lps));
    int len=0,i=1;
    // computing lps array for pattern
    while(i<n){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len>0)len=lps[len-1];
            else    i++;
        }
    }
    vc<int> ans;
    len=0,i=0;
    while(i<n){
        if(p[len]==s[i]){
            len++;i++;
            if(len==m){
                ans.pb(i-m+1);
            }
        }else{
            if(len>0)len=lps[len-1];
            else    i++;
        }
    }
    if(ans.size()){
        cout<<ans.size()<<"\n";
        for(int i:ans)cout<<i<<" ";
    }else cout<<"Not Found";
    cout<<endl<<endl;
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
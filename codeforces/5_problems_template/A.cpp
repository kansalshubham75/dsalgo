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
    vector<int> a(n),b(n),c(n);
    vector<int> ans(n);
    read(a);
    read(b);
    read(c);
    ans[0]=a[0];
    for(int i=1;i<n-1;i++){
        if(ans[i-1]!=a[i])ans[i]=a[i];
        else if(ans[i-1]!=b[i])ans[i]=b[i];
        else ans[i]=c[i];
    }
    if(n>=2){
        if(ans[n-2]!=a[n-1] && ans[0]!=a[n-1])
        ans[n-1]=a[n-1];
        if(ans[n-2]!=b[n-1] && ans[0]!=b[n-1])
        ans[n-1]=b[n-1];
        if(ans[n-2]!=c[n-1] && ans[0]!=c[n-1])
        ans[n-1]=c[n-1];
    }
    for(int i:ans)cout<<i<<" ";
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
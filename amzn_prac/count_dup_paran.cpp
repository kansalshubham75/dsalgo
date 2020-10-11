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
    string s="(((a+b))+((c)))+d";
    stack<int> st;
    int n=s.length(),cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            int in_between=0;
            while(!st.empty() && s[st.top()]!='('){
                st.pop();
                in_between++;
            }
            st.pop();
            if(in_between==0)cnt++;
        }else{
            st.push(i);
        }
    }
    cout<<cnt<<endl;
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
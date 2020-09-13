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
int helper(){
    
}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int f=0,m=0,qc=0;
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='+')  f++;
        if(s1[i]=='-')  f--;
        if(s2[i]=='+')  m++;
        if(s2[i]=='-')  m--;
        if(s2[i]=='?')  qc++;
    }
    int total=pow(2,qc);

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
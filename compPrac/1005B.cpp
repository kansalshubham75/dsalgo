#include <bits/stdc++.h>
using namespace std;
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    int i=s1.size()-1,j=s2.size()-1;
    while(i>=0 && j>=0 && s1[i]==s2[j]){
        i--;
        j--;
    }
    cout<<(i+j+2)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    int oc=0,zc=0;
    for(int i=0;i<n;i++){
        if(str[i]=='0')
            zc++;
        else
            oc++;
    }
    if(n==1 || n==k){
        cout<<str<<endl;
        return;
    }
    // if(k==1){
    //     if(oc>0 && zc>0){
    //         cout<<"IMPOSSIBLE"<<endl;
    //         return;
    //     }else{
    //         cout<<str<<endl;
    //     }
    //     return ;
    // }
    int rep=n/k;
    if(oc%rep!=0 || zc%rep!=0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    string first=str.substr(0,k);
    string next=first;
    reverse(next.begin(),next.end());
    string temp="";
    for(int i=0;i<rep;i++){
        if(i%2==0){
            temp=temp+first;
        }else{
            temp=temp+next;
        }
    }
    if(temp==str){
        cout<<str<<endl;
        return;
    }
    string ans="";
    for(int i=0;i<(zc/rep);i++)
        ans=ans+"0";
    for(int i=0;i<(oc/rep);i++)
        ans=ans+"1";
    next=ans;
    reverse(next.begin(),next.end());
    string ans_="";
    for(int i=0;i<rep;i++){
        if(i%2==0){
            ans_=ans_+ans;
        }else{
            ans_=ans_+next;
        }
    }
    cout<<ans_<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
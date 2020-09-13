#include<iostream>
#include<vector>
using namespace std;
int find(int u,vector<int>& par){
if(u==par[u]){
    return u;
}
int p=find(par[u],par);
par[u]=p;
return p;
}
void merge(int p1,int p2,vector<int>& par){
    if(p1<=p2){
        // cout<<"     "<<p1<<"<"<<p2<<endl;
        par[p2]=p1;
    }else{
        // cout<<"     "<<p2<<"<"<<p1<<endl;
        par[p1]=p2;
    }
}
int getIdx(char a){
    return a-'a';
}
string smallestEquivalentString(string A, string B, string S,vector<int>& par)
{
    for (int i = 0; i < 26; i++)
    {
        par.push_back(i);
    }

    for (int i = 0; i < A.length(); i++)
    {
        int p1 = find(A[i] - 'a',par);
        int p2 = find(B[i] - 'a',par);
        int min_ = min(p1, p2);
        par[p1] = min_;
        par[p2] = min_;
    }

    string ans = "";
    for (int i = 0; i < S.length(); i++)
    {
        int p = find(S[i] - 'a',par);
        ans += (char)(p + 'a');
    }

    return ans;
}
int main(){
    string a="leetcode";
    string b="programs";
    string s="sourcecode";
    vector<int> par(26,-1);
    for(int i=0;i<26;i++){
        par[i]=i;
    }
    for(int i=0;i<a.size();i++){
        int p1=find(getIdx(a[i]),par);
        int p2=find(getIdx(b[i]),par);
        // cout<<p1<<" "<<p2;
        merge(p1,p2,par);
        // cout<<endl;
    }
   
    string ans="";
    for(int i=0;i<s.length();i++){
        char ch=(char)('a'+find((int)(s[i]-'a'),par));  
        ans+=ch;
    }
    cout<<ans<<"\n";
    // vector<int> par1(26,-1);
    // for(int i=0;i<26;i++){
    //     par1[i]=i;
    // }
    // for(int i=0;i<par.size();i++){
    //     cout<<(char)('a'+par[i]);
    // }
    // cout<<endl;
    // cout<<smallestEquivalentString(a,b,s,par1);
    // cout<<endl;
    // for(int i=0;i<par1.size();i++){
    //     cout<<(char)('a'+par1[i]);
    // }  
    return 0;
}
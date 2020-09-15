#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    vector<Node*> children;
    int end;
    int numberWords;
    Node(){
        children.resize(26,NULL);
        end=0;
        numberWords=0;
    }
};
Node* root;
void insert(string& s){
    Node* curr=root;
    int i=0;
    while(i<s.length()){
        int idx=s[i]-'a';
        if(curr->children[idx]==NULL){
            curr->children[idx]=new Node();
        }
        curr->numberWords++;
        curr=curr->children[idx];
        i++;
    }
    curr->numberWords++;
    curr->end++;
}
int solveQ(string& s,int idx,Node* curr){
    if(curr==NULL)
        return 0;
    if(idx==s.length())
        return curr->numberWords;
    int count=0;
    if(s[idx]=='?'){
        for(int i=0;i<26;i++){
            count+=solveQ(s,idx+1,curr->children[i]);
        }
        return count;
    }
    return solveQ(s,idx+1,curr->children[s[idx]-'a']);
}
int main(){
    int n;
    cin>>n;
    int h[n],in[n];

    for(int i=0;i<n;i++)
        cin>>h[i]>>in[i];
    for(int i=0;i<n;i++){
        int ans=0;
        for(int j=i;j<n;j++){
               if(h[i]<=h[j])
                    ans+=(in[i]-in[j]);
                else
                    ans+=(in[j]-in[i]);
                cout<<ans<<endl;
        }
        cout<<"->"<<ans<<endl;
    }
    return 0;
}
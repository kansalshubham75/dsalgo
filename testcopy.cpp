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
    root=new Node();
    int n,m;
    cin>>n>>m;
    while(n--){
        string s;
        cin>>s;
        insert(s);
    }
    while(m--){
        string s;
        cin>>s;
        cout<<solveQ(s,0,root)<<endl;
    }
    return 0;
}
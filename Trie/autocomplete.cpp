#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pb push_back
#define vc vector
class Node{
        public:
        vector<Node*> children;
        priority_queue<pii> q;
        Node(){
            children.resize(255,NULL);
        }
};
class Autocomplete{
    Node* root;
    public:
    Autocomplete(){
        root=new Node();
    }
    //===============INITIALIZE TRIE=====================//
    private : void insert_word(string& s,int pos){
        Node* curr=root;
        int i=0;
        while(i<s.length()){
            int idx=(int)s[i];
            if(curr->children[idx]==NULL)   curr->children[idx]=new Node();

            curr=curr->children[idx];
        }
    }
    void initialize(vector<string>& dict){
        int i=0;
        for(auto& s:dict)
            insert_word(s,i++);
    }
    //===================PROCESS QUERY========================//
    void input(){
        
    }
};
void read(vector<int>& arr){
    for(int i=0;i<arr.size();i++)
        cin>>arr[i];
}
void solve(){
    
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
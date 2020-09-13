#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int val;
    Node(int val){
        this->val=val;
    }
};
vector<int> val={1,2,4,-1,-1,5,-1,-1,3,6,-1,-1,-1};
int idx=0;
Node* root;
Node* construct_tree(){
    if(val[idx]==-1){
        idx++;
        return NULL;
    }
    Node* n=new Node(val[idx]);
    idx++;
    n->left=construct_tree();
    n->right=construct_tree();
}
void iterative_inorder(){
    stack<Node*> st;
    Node* curr=root;
    while(curr!=NULL || !st.empty()){
        while(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        //process curr
        cout<<curr->val<<" ";
        curr=curr->right;
    }
} 
void iterative_preorder(){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* rn=st.top();st.pop();
        cout<<rn->val<<" ";
        if(rn->right)   st.push(rn->right);
        if(rn->left)   st.push(rn->left);
    }
}
void print(Node* node){
    if(node==NULL) {cout<<-1<<" "; return;}
    cout<<node->val<<" ";
    print(node->left);
    print(node->right);
}
int main(){
    root=construct_tree();
    // print(root);
    // iterative_inorder();
    // iterative_preorder();
    return 0;
}
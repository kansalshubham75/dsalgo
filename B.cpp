// C++ program to print the nodes of binary 
// tree as they become the leaf node 

#include <bits/stdc++.h> 
using namespace std; 

// Binary tree node 
struct Node { 
	int data; 
	// int order; 
	struct Node* left; 
	struct Node* right; 
}; 

// Utiltiy function to allocate a new node 
struct Node* newNode(int data, int order) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	// node->order = order; 
	node->left = NULL; 
	node->right = NULL; 

	return (node); 
} 

unordered_map<int,vector<Node*>> m;
int dfs(Node* n){
    if(n==NULL)return 0;

    int l=dfs(n->left);
    int r=dfs(n->right);

    int myOrder=max(l,r)+1;
    m[myOrder].push_back(n);
    return myOrder;
}
// Driver Code 
int main() 
{ 
	struct Node* root = newNode(8, 0); 
	root->left = newNode(3, 0); 
	root->right = newNode(10, 0); 
	root->left->left = newNode(1, 0); 
	root->left->right = newNode(6, 0); 
	root->right->left = newNode(14, 0); 
	root->right->right = newNode(4, 0); 
	root->left->left->left = newNode(7, 0); 
	root->left->left->right = newNode(13, 0); 
    dfs(root);
    int i=1;
    while(!m.empty()){
        vector<Node*> leafs=m[i];
        for(int i=0;i<leafs.size();i++)cout<<leafs[i]->data<<" ";
        cout<<endl;
        m.erase(i);
        i++;
    }
	return 0; 
} 

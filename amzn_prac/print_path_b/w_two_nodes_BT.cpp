// C++ program to print path between any 
// two nodes in a Binary Tree 
#include <bits/stdc++.h> 
using namespace std; 

// structure of a node of binary tree 
struct Node { 
	int data; 
	Node *left, *right; 
}; 

struct Node* getNode(int data) 
{ 
	struct Node* newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return newNode; 
} 
bool getRootToNodePath(Node* node,vector<int>& path,int val){
    if(!node)return 0;
    path.push_back(node->data);
    bool left=getRootToNodePath(node->left,path,val);
    bool right=getRootToNodePath(node->right,path,val);
    if(val==node->data || left || right)return true;
    path.pop_back();
    return false;
}
void printPathBetweenNodes(Node* root, int n1, int n2) 
{ 
	 vector<int> p1,p2;
     getRootToNodePath(root,p1,n1);
     getRootToNodePath(root,p2,n2);
     vector<int> path;
     int i=0;
     while(p1[i]==p2[i])i++;
     for(int j=p1.size()-1;j>=i;j--)path.push_back(p1[j]);
     path.push_back(p1[i-1]);
     for(int j=i;j<p2.size();j++)path.push_back(p2[j]);
     for(int i:path)cout<<i<<" ";   
} 
unordered_set<int> vis;
void helper(Node* root,int v1,int v2,stack<int>& st,int& found){
    if(root==NULL)return;
    if(found==0 && (root->data==v1 || root->data==v2))found=1;
    if(found==1){
        st.push(root->data);
        vis.insert(root->data);
    }
    
}
// Driver program 
int main() 
{ 
	// binary tree formation 
	struct Node* root = getNode(0); 
	root->left = getNode(1); 
	root->left->left = getNode(3); 
	root->left->left->left = getNode(7); 
	root->left->right = getNode(4); 
	root->left->right->left = getNode(8); 
	root->left->right->right = getNode(9); 
	root->right = getNode(2); 
	root->right->left = getNode(5); 
	root->right->right = getNode(6); 

	int node1 = 7; 
	int node2 = 5; 
	printPathBetweenNodes(root, node1, node2); 
	return 0; 
} 

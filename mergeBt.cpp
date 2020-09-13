// { Driver Code Starts
#include <bits/stdc++.h>
#include<string>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



vector<int> merge(Node *root1,Node *root2);

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/* The structure of Node is

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
Node* merge1(Node* l1,Node* l2){
    struct Node* h1=l1->right;
    
    l1->right=l2->right;
    l2->right->left=l1;
    h1->left=l2;
    l2->right=h1;
    return l2;
}

Node* helper(Node* node){
    if(node==NULL)
        return NULL;
    struct Node* l=helper(node->left);
    struct Node* r=helper(node->right);
    
    node->left=node;
    node->right=node;
    struct Node* t=node;
    if(l!=NULL)
        t=merge1(l,t);
    if(r!=NULL)
        t=merge1(t,r);
    
    return t;
}

Node *bTreeToCList(Node *root)
{
//add code here
    return helper(root)->right;
}
Node* merge_(Node* l1,Node* l2){
    struct Node* i=l1;
    struct Node* j=l2;
    struct Node* d=new Node(-1);
    struct Node* temp=d;
    l1->left=NULL;
    l2->left=NULL;
    while(i!=NULL && j!=NULL){
        if(i->data<j->data){
            temp->right=i;
            i->left=temp;
            i=i->right;
        }else{
            temp->right=j;
            j->left=temp;
            j=j->right;
        }
        temp=temp->right;
    }
    while(i!=NULL){
        temp->right=i;
            i->left=temp;
            i=i->right;
        temp=temp->right;
    }
    
    while(j!=NULL){
            temp->right=j;
            j->left=temp;
            j=j->right;
            temp=temp->right;
    }
    return d->right;
}
// Return a integer of integers having all the nodes in both the BSTs in a sorted order.
vector<int> merge(Node *root1, Node *root2)
{
   //Your code here
   struct Node* l1=bTreeToCList(root1);
   struct Node* l2=bTreeToCList(root2);
   struct Node* l=merge_(l1,l2);
   vector<int> ans;
   while(l!=NULL){
       ans.push_back(l->data);
       l=l->right;
   }
}
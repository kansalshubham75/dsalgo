#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
    }
};

int idx = 0;

Node *createFromPre(vector<int> &arr)
{
    if (idx >= arr.size() || arr[idx] == -1)
    {
        idx++;
        return NULL;
    }
    Node *node = new Node(arr[idx]);
    cout<<arr[idx]<<" -> "<<idx<<" ,";
    idx++;
    node->left = createFromPre(arr);
    node->right = createFromPre(arr);
    return node;
}

void display(Node *node)
{
    if (node == NULL)
        return;
    
    display(node->left);
    cout << node->val << " ";
    display(node->right);
}
unordered_map<Node *, int> level;
unordered_map<Node *, Node *> parent;
unordered_map<int, Node *> valtonode;
unordered_map<Node *, Node *> gp; //grandParent of every Node
int nl = 0;
void fillMap(Node *node, int l)
{   if(node==NULL)
        return;
    level[node] = l;
    valtonode[node->val] = node;
    nl = max(nl, l);
    if (node->left)
    {
        parent[node->left] = node;
        fillMap(node->left, l + 1);
    }
    if (node->right)
    {
        parent[node->right] = node;
        fillMap(node->right, l + 1);
    }
}
void fillGp(Node *node, int l, int rootl)
{
    if (node == NULL)
        return;
    if (l == rootl)
    {
        gp[node] = parent[node];
    }
    else
    {
        gp[node] = gp[parent[node]];
    }

    fillGp(node->left, l + 1, rootl);
    fillGp(node->right, l + 1, rootl);
}
void preprocessTree(Node *node)
{
    fillMap(node, 0);
    fillGp(node, 0, ceil(sqrt(nl)));
}

Node* getLca(int v1, int v2)
{
    int sqrtl = sqrt(nl);
    Node *n1 = valtonode[v1];
    Node *n2 = valtonode[v2];

    while (1)
    {
        int lev1 = level[n1] % sqrtl;
        int lev2 = level[n2] % sqrtl;
        if (lev1 == lev2)
            break;
        if (lev1 < lev2)
        {
            n2 = gp[n2];
        }
        else
        {
            n1 = gp[n1];
        }
    }

    while (1)
    {
        int l1 = level[n1];
        int l2 = level[n2];
        if (l1 == l2)
            break;
        if (l1 < l2)
        {
            n2 = parent[n2];
        }
        else
        {
            n1 = parent[n1];
        }
    }

    while(gp[n1]!=gp[n2]){
        n1=gp[n1];
        n2=gp[n2];
    }

    while(parent[n1]!=parent[n2]){
        n1=parent[n1];
        n2=parent[n2];
    }
    return parent[n1];
}
int main()
{
    vector<int> arr = {100, 50, 25, 12, -1, -1, 40, 35, 32, 31, -1, -1, -1, -1, 45, -1, -1, 75, 150, 125, -1, 130, -1, 135, 133, -1, 175};
    Node *root = createFromPre(arr);
    display(root);
    preprocessTree(root);
    // cout<<"===============Level===================="<<endl;
    // for(auto p:level){
    //     cout<<p.first->val<<" "<<p.second<<endl;
    // }
    // cout<<"===============Parent===================="<<endl;
    // for(auto p:parent){
    //     cout<<p.first->val<<" "<<p.second->val<<endl;
    // }
    // cout<<"===============GP===================="<<endl;
    // for(auto p:gp){
    //     cout<<p.first->val<<" "<<p.second->val<<endl;
    // }
    // int t;
    // cin>>t;
    // while(t--){
    //     int v1,v2;
    //     cin>>v1>>v2;
    //     cout<<getLca(v1,v2)->val<<endl;
    // }
    return 0;
}
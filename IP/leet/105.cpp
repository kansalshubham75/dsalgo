#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
public:
    unordered_map<int,int> m;
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int psi,int pei,int isi,int iei){
        if(isi>iei)
            return nullptr;
        TreeNode* node=new TreeNode(preorder[psi]);
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }


    }
};
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //=======================Q863. All Nodes Distance K in Binary Tree======================================//
vector<TreeNode*> rootToNodePath(TreeNode* node,int data){
        if(node==NULL){
            vector<TreeNode*> a;
            return a;
        }
        if(node->val==data){
            vector<TreeNode*> small;
            small.push_back(node);
            return small;
        }
        
        vector<TreeNode*> l=rootToNodePath(node->left,data);
        if(l.size()!=0){
            l.push_back(node);
            return l;
        }
        vector<TreeNode*> r=rootToNodePath(node->right,data);
        if(r.size()!=0){
            r.push_back(node);
            return r;
        }

        return l;
    }
    vector<int> ans;
    void kaway(TreeNode* node,TreeNode* rnode,int k){
        if(node==NULL || node==rnode){
            return ;
        }
        if(k==0){
            ans.push_back(node->val);
            return;
        }

        kaway(node->left,rnode,k-1);
        kaway(node->right,rnode,k-1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<TreeNode*> rtnp=rootToNodePath(root,target->val);
        kaway(rtnp[0],NULL,k);
        for(int i=1;i<rtnp.size();i++){
            kaway(rtnp[i],rtnp[i-1],k-i);
        }
        return ans;
    }

    
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

TreeNode *Uroot;

class Solution {
    
    bool finddata(TreeNode *root, int data, TreeNode *node)
    {
        if(root==NULL)
        {
            return false;
        }
        
        if(root->val==data && root!=node)
        {
            return true;
        }
        
        if(data<root->val)
        {
            return finddata(root->left,data,node);
        }
        else
        {
            return finddata(root->right,data,node);
        }
    }
    
    
    bool solve(TreeNode* root, int k, TreeNode *Uroot)
    {
        if(root==NULL)
        {
            return false;
        }
        
        int data=k-root->val;
        bool isfound=finddata(Uroot,data,root);
        if(isfound) return true;
        
        bool leftans=solve(root->left,k,Uroot);
        if(leftans) return leftans;
        return solve(root->right,k,Uroot);
        
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        
        if(root==NULL)
        {
            return false;
        }
        
        Uroot=root;
        
        return solve(root,k,Uroot);
        
    }
};
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




class Solution {
    
    bool isOne(TreeNode* root)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(root->val==1) return true;
            
            delete root;
            return false;
        }
        
        bool isLeftOne=isOne(root->left);
        bool isRightOne=isOne(root->right);
        
        if(isLeftOne==false && isRightOne==false)
        {
            if(root->val==0)
            {
                delete root;
                return false;
            }
            else
            {

                root->left=NULL;
                root->right=NULL;
                
                return true;
            }
        }
        else if(isLeftOne==false)
        {
            root->left=NULL;
            
            return true;
        }
        else if(isRightOne==false)
        {
            root->right=NULL;
            
            return true;
        }
        else
        {
            return true;
        }
        
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if(root==NULL) return NULL;
        
        bool ans=isOne(root);
        
        if(ans==false) return NULL;
        
        return root;
        
    }
};
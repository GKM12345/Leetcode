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

class Pair{
  
    public:
      bool isbalanced;
      int height;
    
};

class Solution {
    
    Pair helper(TreeNode *root)
    {
        if(root==NULL)
        {
            Pair ans;
            ans.isbalanced=true;
            ans.height=0;
            return ans;
        }
        
        Pair leftchild=helper(root->left);
        Pair rightchild=helper(root->right);
        
        Pair ans;
        
        if(leftchild.isbalanced==false || rightchild.isbalanced==false)
        {
            ans.isbalanced=false;
            ans.height=1+max(leftchild.height,rightchild.height);
        }
        else
        {
            if(abs(leftchild.height-rightchild.height)<=1)
            {
                ans.isbalanced=true;
            }
            else
            {
                ans.isbalanced=false;
            }
            ans.height=1+max(leftchild.height,rightchild.height);
        }
        
        return ans;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        
        Pair ans=helper(root);
        return ans.isbalanced;
        
    }
};
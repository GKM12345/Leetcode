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

class Triple{
    
    public :
    
        long long max;
        long long min;
        bool isBST;
};


class Solution {
    
    Triple helper(TreeNode *root)
    {
        if(root==NULL)
        {
            Triple ans;
            ans.max=-2147483649;
            ans.min=2147483649;
            ans.isBST=true;
            return ans;
        }
        
        Triple ans;
        Triple leftans=helper(root->left);
        Triple rightans=helper(root->right);
        if(leftans.isBST==false || rightans.isBST==false)
        {
            ans.isBST=false;
        }
        else if(root->val>leftans.max && root->val<rightans.min)
        {
            ans.isBST=true;
            ans.min=min((long long)root->val,leftans.min);
            ans.max=max((long long)root->val,rightans.max);
        }
        else
        {
            ans.isBST=false;
        }
        return ans;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        
        Triple ans =helper(root);
        return ans.isBST;
        
    }
};
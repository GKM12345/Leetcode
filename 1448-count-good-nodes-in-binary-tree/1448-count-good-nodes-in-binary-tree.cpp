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
    
    void helper(TreeNode *root, int Max, int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val>=Max)
        {
            ans++;
            Max=root->val;
        }
        helper(root->left,Max,ans);
        helper(root->right,Max,ans);
    }
    
public:
    int goodNodes(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        int Maxval=INT_MIN;
        int ans=0;
        helper(root,Maxval,ans);
        
        return ans;
        
    }
};
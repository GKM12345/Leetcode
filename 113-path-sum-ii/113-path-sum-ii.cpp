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
    
    void helper(TreeNode *root, int s, vector<int> &path, vector<vector<int>> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            if(s==root->val)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();
            }
            return;
        }
        
        path.push_back(root->val);
        helper(root->left,s-root->val,path,ans);
        helper(root->right,s-root->val,path,ans);
        path.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> path;
        vector<vector<int>> ans;
        
        if(root==NULL)
        {
            return ans;
        }
        
        helper(root,targetSum,path,ans);
        return ans;
    }
};
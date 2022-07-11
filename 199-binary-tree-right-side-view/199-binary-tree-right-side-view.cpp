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
    
    void RightViewOfBT(TreeNode *root, int height, int &maxheight, vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(height>maxheight)
        {
            maxheight=height;
            ans.push_back(root->val);
        }
        
        RightViewOfBT(root->right,height+1,maxheight,ans);
        RightViewOfBT(root->left,height+1,maxheight,ans);
        
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        
        int maxheight=-1;
        vector<int> ans;
        RightViewOfBT(root,0,maxheight,ans);
        return ans;
        
    }
};
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
public:
    string tree2str(TreeNode* root) {
        
        if(root==NULL)
        {
            return "";
        }
        if(root->left==NULL && root->right==NULL)
        {
            return to_string(root->val);
        }
        
        string leftans=tree2str(root->left);
        string rightans=tree2str(root->right);
        
            leftans="("+leftans;
            leftans+=")";
        if(rightans.size()>0)
        {
            rightans="("+rightans;
            rightans+=")";
        }
        
        string ans=to_string(root->val);
        ans+=leftans;
        ans+=rightans;
        
        return ans;
        
        
    }
};
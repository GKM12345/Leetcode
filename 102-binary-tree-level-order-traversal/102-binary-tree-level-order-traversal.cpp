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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        
        vector<int> anspart;
        int i=0;
        while(!pendingNodes.empty())
        {
            TreeNode *temp=pendingNodes.front();
            pendingNodes.pop();
            if(temp==NULL)
            {
                if(pendingNodes.size()!=0)
                {
                    pendingNodes.push(NULL);
                }
                ans.push_back(anspart);
                anspart.erase(anspart.begin(),anspart.end());
                
            }
            else
            {
                anspart.push_back(temp->val);
                if(temp->left!=NULL) pendingNodes.push(temp->left);
                if(temp->right!=NULL) pendingNodes.push(temp->right);
            }
        }
        
        return  ans;
        
        
    }
};
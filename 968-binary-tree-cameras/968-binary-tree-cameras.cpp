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
    
    int req(TreeNode* root, int &ans)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return -1;
        }
        
        int ans1=req(root->left, ans);
        int ans2=req(root->right,ans);
        
        if(ans1==-1 || ans2==-1)
        {
            ans++;
            return 0;
        }
        else if(ans1==0 || ans2==0)
        {
            return 1;
        }
        
        return -1;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        
        if(root==NULL)
        {
            return 0;
        }
        
        int ans=0;
        if(req(root,ans)==-1)
        {
            ans++; 
        }
        
        return ans;
        
    }
};
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
    
    void solve(TreeNode *root, int ch, int &h, vector<double> &val, vector<int> &count)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(ch>h)
        {
            h=ch;
            val.push_back(root->val);
            count.push_back(1);
        }
        else
        {
            val[ch]+=root->val;
            count[ch]++;
        }
        
        solve(root->left,ch+1,h,val,count);
        solve(root->right,ch+1,h,val,count);
    }
    
public:
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> val;
        vector<int> count;
        int h=-1;
        
        solve(root,0,h,val,count);
        
        for(int i=0;i<val.size();i++)
        {
            val[i]/=count[i];
        }
        
        return val;
        
    }
};
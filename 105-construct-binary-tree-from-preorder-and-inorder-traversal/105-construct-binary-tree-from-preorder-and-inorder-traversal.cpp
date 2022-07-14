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
    
    TreeNode* helper(vector<int>& preorder, int presi, int preei, vector<int> &inorder, int insi, int inei)
    {
        if(insi>inei || presi>preei)
        {
            return NULL;
        }
        int rootdata=preorder[presi];
        TreeNode *root=new TreeNode(rootdata);
        int rootindex=insi;
        while(inorder[rootindex]!=rootdata)
        {
            rootindex++;
        }
        
        
        int Linsi=insi,Linei=rootindex-1;
        int Rinsi=rootindex+1,Rinei=inei;
        
        int Lpresi=presi+1;
        int Lpreei=(Linei-Linsi)+Lpresi;
        int Rpresi=Lpreei+1,Rpreei=preei;
        
        
        TreeNode *leftans=helper(preorder,Lpresi,Lpreei,inorder,Linsi,Linei);
        TreeNode *rightans=helper(preorder,Rpresi,Rpreei,inorder,Rinsi,Rinei);
        
        root->left=leftans;
        root->right=rightans;
        
        return root;
        
        
        
    }
    
    
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preei=preorder.size()-1,presi=0;
        int inei=inorder.size()-1,insi=0;
        
        TreeNode *root=helper(preorder,presi,preei,inorder,insi, inei);
        
        return root;
        
    }
};
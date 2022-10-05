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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(root==NULL)
        {
            return NULL;
        }
        
        if(depth==1)
        {
            TreeNode *Node=new TreeNode(val);
            Node->left=root;
            return Node;
        }
        
        if(depth==2)
        {
            TreeNode *leftchild=root->left;
            TreeNode *rightchild=root->right;
            
            TreeNode *Node1=new TreeNode(val);
            TreeNode *Node2=new TreeNode(val);
            
            root->left=Node1;
            root->right=Node2;
            
            Node1->left=leftchild;
            Node2->right=rightchild;
            
            return root;
            
        }
        
        TreeNode *leftchild= addOneRow(root->left,val,depth-1);
        TreeNode *rightchild=addOneRow(root->right,val,depth-1);
        
        return root;
    }
};
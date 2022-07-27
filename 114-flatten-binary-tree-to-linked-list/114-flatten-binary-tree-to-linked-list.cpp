class Pair{
    
    public:
      TreeNode *first,*last;
    
};

class Solution {
    
    Pair helper(TreeNode *root)
    {
        if(root==NULL)
        {
            Pair ans;
            ans.first=NULL;
            ans.last=NULL;
            return ans;
        }
        Pair Leftans=helper(root->left);
        Pair Rightans=helper(root->right);
        
        Pair ans;
        if(Leftans.first==NULL && Rightans.first==NULL)
        {
            ans.first=root;
            ans.last=root;
        }
        else if(Leftans.first==NULL)
        {
            root->right=Rightans.first;
            ans.first=root;
            ans.last=Rightans.last;
        }
        else if(Rightans.first==NULL)
        {
            root->right=Leftans.first;
            root->left=NULL;
            ans.first=root;
            ans.last=Leftans.last;
        }
        else
        {
            root->right=Leftans.first;
            root->left=NULL;
            Leftans.last->right=Rightans.first;
            ans.first=root;
            ans.last=Rightans.last;
        }
        
        return ans;
    }
    
public:
    void flatten(TreeNode* root) {
        
        Pair ans=helper(root);
        // return ans.first;
        
    }
};
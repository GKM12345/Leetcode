/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
       
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        
        queue<Node*> pendingNodes;
        vector<int> val;
        
        pendingNodes.push(root);
        pendingNodes.push(NULL);
        
        while(pendingNodes.size()!=0)
        {
            Node *treenode=pendingNodes.front();
            val.push_back(treenode->val);
            pendingNodes.pop();
            
            for(int i=0;i<treenode->children.size();i++)
            {
                pendingNodes.push(treenode->children[i]);
            }
            
            if(pendingNodes.front()==NULL)
            {
                ans.push_back(val);
                val.erase(val.begin(),val.end());
                if(pendingNodes.size()==1)
                {
                    pendingNodes.pop();;
                }
                else
                {
                    pendingNodes.pop();
                    pendingNodes.push(NULL);
                }
            }
        }
        
        return ans;
    }
};
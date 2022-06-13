/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL) return NULL;
        
        unordered_map<Node*,Node*> mp;
        queue<Node*> pendingNodes;
        pendingNodes.push(node);
        Node *root=new Node(node->val);
        mp[node]=root;
        
        while(pendingNodes.size()!=0)
        {
            Node *temp=pendingNodes.front();
            pendingNodes.pop();
            
            for(Node *curr:temp->neighbors)
            {
                if(!mp[curr])
                {
                    Node *n=new Node(curr->val);
                    mp[curr]=n;
                    pendingNodes.push(curr);
                }
                (mp[temp]->neighbors).push_back(mp[curr]);
                
            }
        }
        
        return root;
        
    }
};
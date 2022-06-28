class Solution {
    
    int dfs(vector<int> *adj, int node, vector<int> &ans, vector<int> &quite)
    {
        if(adj[node].size()==0)
        {
            ans[node]=node;
            return node;
        }
        
        int val=quite[node];
        int ans1=node;
        for(auto it:adj[node])
        {
            int smallnode;
            if(ans[it]!=INT_MAX)
            {
                smallnode=ans[it];
            }
            else
            {
                smallnode=dfs(adj,it,ans,quite);
            }
            
            if(quite[smallnode]<val)
            {
                val=quite[smallnode];
                ans1=smallnode;
            }
        }
        ans[node]=ans1;
        return ans1;
        
    }
    
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        int n=quiet.size();
        vector<int> adj[n];
        
        for(int i=0;i<richer.size();i++)
        {
            adj[richer[i][1]].push_back(richer[i][0]);
        }
        
        vector<int> ans(n,INT_MAX);
        for(int i=0;i<n;i++)
        {
            if(ans[i]==INT_MAX)
            {
               int val= dfs(adj,i,ans,quiet);
            }
        }
        
        return ans;
        
    }
};
class Solution {
    
    void dfs(vector<int> adj[], int node, vector<int> &visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                dfs(adj,it,visited);
            }
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        
        int edges=connections.size();
        if(edges<n-1)
        {
            return -1;
        }
        
        vector<int> visited(n,0);
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(adj,i,visited);
                ans++;
            }
        }
        
        return ans-1;
        
    }
};
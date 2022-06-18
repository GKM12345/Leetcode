class Solution {
    
    bool helper(vector<int> *adj, int n, int s, int d, vector<bool> &visited)
    {
        if(s==d) return true;
        visited[s]=true;
        for(int i=0;i<adj[s].size();i++)
        {
            if(visited[adj[s][i]]==false)
            {
                bool found=helper(adj,n,adj[s][i],d,visited);
                if(found==true) return true;
            }
            
        }
        
        return false;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(n,false);
        return helper(adj,n,source,destination, visited);
        
    }
};
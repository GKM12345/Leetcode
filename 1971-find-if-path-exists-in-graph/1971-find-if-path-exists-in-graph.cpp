class Solution {
    
    bool bfs(vector<int> *adj, int n, int s, int d)
    {
        vector<int> visited(n,0);
        queue<int> Q;
        Q.push(s);
        visited[s]=true;
        while(Q.size()!=0)
        {
            int node=Q.front();
            Q.pop();
            if(node==d) return true;
            for(int i=0;i<adj[node].size();i++)
            {
                if(visited[adj[node][i]]==false)
                {
                    Q.push(adj[node][i]);
                    visited[adj[node][i]]=true;
                }
            }
        }
        
        return false;
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        return bfs(adj,n,source,destination);
        
    }
};
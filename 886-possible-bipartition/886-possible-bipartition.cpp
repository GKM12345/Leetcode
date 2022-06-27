class Solution {
    
    bool bipartite(vector<int> *adj, int node, vector<int> &like, int color)
    {
        like[node]=color;
        for(auto it:adj[node])
        {
            if(like[it]==color)
            {
                return false;
            }
            else if(like[it]==-1)
            {
               int colour;
                if(color==0) colour=1;
                else colour=0;
                bool ans=bipartite(adj,it,like,colour);
                if(ans==false)
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        for(int i=0;i<dislikes.size();i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        vector<int> like(n+1,-1);
        
        for(int i=1;i<=n;i++)
        {
            if(like[i]==-1)
            {
                bool ans=bipartite(adj,i,like,0);
                if(ans==false)
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};
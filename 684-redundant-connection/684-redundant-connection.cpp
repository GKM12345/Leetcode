vector<int> parent(1001);
vector<int> Rank(1001);

class Solution {
    
    int par(int u)
    {
        if(parent[u]==u)
        {
            return u;
        }
        
        return parent[u]=par(parent[u]);
    }
    
    void Union(int u, int v)
    {
        u=par(u);
        v=par(v);
        
        if(Rank[u]>Rank[v])
        {
            parent[v]=u;
        }
        else if(Rank[u]<Rank[v])
        {
            parent[u]=v;
        }
        else
        {
            parent[u]=v;
            Rank[v]++;
        }
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        
        for(int i=0;i<n+1;i++)
        {
            parent [i]=i;
            Rank[i]=1;
        }
        vector<int> ans;
        
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            
            if(par(u)!=par(v))
            {
                Union(u,v);
            }
            else
            {
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
        }
        
        return ans;
        
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        unordered_set<int> adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ans=adj[i].size()+adj[j].size();
                if(adj[i].count(j)>0)
                {
                    ans--;
                }
                
                maxi=max(maxi,ans);
            }
        }
        
        return maxi;
        
    }
};
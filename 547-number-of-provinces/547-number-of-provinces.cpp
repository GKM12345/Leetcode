class Solution {
    
void dfs(vector<vector<int>>& isConnected, int node, vector<bool> &visited)
{
    visited[node]=true;
    for(int i=0;i<isConnected[node].size();i++)
    {
        if(i!=node && isConnected[node][i]==1 && visited[i]==false)
        {
            dfs(isConnected,i,visited);
        }
    }
}
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<bool> visited(n,0);
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                ans++;
                dfs(isConnected,i,visited);
            }
        }
        
        return ans;
    }
};
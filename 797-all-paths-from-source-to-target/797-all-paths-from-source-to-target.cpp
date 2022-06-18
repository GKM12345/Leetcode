class Solution {
    
    void helper(vector<vector<int>>& graph, int si, int n, vector<int> &val, vector<vector<int>> &ans)
    {
        if(si==n-1)
        {
            val.push_back(si);
            ans.push_back(val);
            val.pop_back();
            return;
        }
        val.push_back(si);
        for(int i=0;i<graph[si].size();i++)
        {
            helper(graph,graph[si][i],n,val,ans);
        }
        val.pop_back();
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<vector<int>> ans;
        vector<int> val;
        
        helper(graph,0,n,val,ans);
        return ans;
        
    }
};
class Solution {
    
    void toposort(vector<int> *adj, vector<int> &indeg, vector<int> &ans, int n)
    {
        queue<int> Q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                Q.push(i);
            }
        }
        int count=0;
        while(Q.size()!=0)
        {
            int node=Q.front();
            Q.pop();
            count++;
            for(int i=0;i<adj[node].size();i++)
            {
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0)
                {
                    Q.push(adj[node][i]);
                }
            }
            ans.push_back(node);
        }
        if(n!=count)
            ans.erase(ans.begin(),ans.end());
    }
    
public:
    vector<int> findOrder(int numcourses, vector<vector<int>>& prerequisites) {
        
        int n=prerequisites.size();
        vector<int> adj[numcourses];
        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> indeg(numcourses,0);
        for(int i=0;i<numcourses;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                indeg[adj[i][j]]++;
            }
        }
        
        vector<int> ans;
        
        toposort(adj,indeg,ans,numcourses);
        return ans;
        
    }
};
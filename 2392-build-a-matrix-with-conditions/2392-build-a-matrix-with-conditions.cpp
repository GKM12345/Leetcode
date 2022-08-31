class Solution {
    
    vector<int> Topo(vector<vector<int>> &edges, int n)
    {
        vector<int> adj[n+1];
        vector<int> indeg(n+1,0);
        for(int i=0;i<edges.size();i++)
        {
            indeg[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> ans;
        queue<int> Q;
        
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)
            {
                Q.push(i);
            }
        }
        
        while(Q.size()>0)
        {
            int node=Q.front();
            ans.push_back(node);
            Q.pop();
            for(int i=0;i<adj[node].size();i++)
            {
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0)
                {
                    Q.push(adj[node][i]);
                }
            }
        }
                         
        return ans;
        
    }
    
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int>> ans;
        
        vector<int> updown=Topo(rowConditions,k);
        if(updown.size()!=k) return {};
        
        vector<int> leftright=Topo(colConditions,k);
        if(leftright.size()!=k) return {};
        
        
        vector<pair<int,int>> pos(k+1);
        for(int i=0;i<updown.size();i++)
        {
            pos[updown[i]].first=i;
        }
        for(int i=0;i<leftright.size();i++)
        {
            pos[leftright[i]].second=i;
        }
        
        
        vector<vector<int>> answer(k,vector<int>(k,0));
        
        for(int i=1;i<pos.size();i++)
        {
            answer[pos[i].first][pos[i].second]=i;
        }
        
        return answer;
        
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        set<int> adj[n+1];
        for(int i=0;i<trust.size();i++)
        {
            adj[trust[i][0]].insert(trust[i][1]);
        }
        
        vector<int> judge;
        
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()==0)
            {
                judge.push_back(i);
            }
        }
        
        if(judge.size()==0) return -1;
        
        for(int i=0;i<judge.size();i++)
        {
            int jdg=judge[i];
            bool found=true;
            for(int j=1;j<=n;j++)
            {
                if(j!=jdg && adj[j].count(jdg)==0)
                {
                    found=false;
                    break;
                }
            }
            if(found==true)
            {
                return jdg;
            }
            
        }
        
        return -1;
        
    }
};
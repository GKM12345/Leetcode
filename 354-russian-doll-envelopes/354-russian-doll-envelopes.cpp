
bool comperator(const pair<int,int> &p1, const pair<int,int> &p2)
{
    if(p1.first==p2.first)
    {
        return p2.second<p1.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}

class Solution {
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        int n=envelopes.size();
        vector<pair<int,int>> V;
        for(int i=0;i<n;i++)
        {
            V.push_back({envelopes[i][0],envelopes[i][1]});
        }
        
        sort(V.begin(),V.end(),comperator);
        
        int max=1;
        vector<int> ans;
        ans.push_back(V[0].second);
        for(int i=1;i<n;i++)
        {
            if((V[i].second>ans[max-1]))
            {
                ans.push_back(V[i].second);
                max++;
            }
            else
            {
                int idx=lower_bound(ans.begin(),ans.end(),V[i].second)-ans.begin();
                ans[idx]=V[i].second;
            }
            
        }
        return max;
        
        
    }
};
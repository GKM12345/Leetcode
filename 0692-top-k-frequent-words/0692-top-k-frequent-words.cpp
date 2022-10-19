bool cmp(pair<string,int> &p1, pair<string,int> &p2)
{
    if(p1.second!=p2.second)
    {
        return p1.second>p2.second;
    }
    
    return p1.first<p2.first;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n=words.size();
        map<string,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        
        vector<pair<string,int>> V;
        
        for(auto& it:mp)
        {
           V.push_back(it);
        }
        
        sort(V.begin(),V.end(),cmp);
        
        vector<string> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(V[i].first);
        }
        
        return ans;
        
    }
};
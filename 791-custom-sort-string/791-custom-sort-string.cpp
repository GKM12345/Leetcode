bool cmp(pair<char,int> &p1, pair<char,int> &p2)
{
    return p1.second<p2.second;
}

class Solution {
public:
    string customSortString(string order, string s) {
        
        int rank[26]={INT_MAX};
        
        int m=order.size();
        
        for(int i=0;i<m;i++)
        {
            rank[order[i]-'a']=i;
        }
        
        vector<pair<char,int>> v;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            v.push_back({s[i],rank[s[i]-'a']});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            ans+=v[i].first;
        }
        
        return ans;
        
    }
};
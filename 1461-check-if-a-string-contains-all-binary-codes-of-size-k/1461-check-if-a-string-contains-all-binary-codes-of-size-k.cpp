class Solution {
    
public:
    bool hasAllCodes(string s, int k) {
        
        int need=1<<k;
        int n=s.size();
        unordered_set<string> Set;
        for(int i=0;i<=n-k;i++)
        {
            string str=s.substr(i,k);
            if(Set.count(str)==0)
            {
                Set.insert(str);
                need--;
            }
            if(need==0) return true;
        }
        
        if(need==0) return true;
        return false;
        
    }
};
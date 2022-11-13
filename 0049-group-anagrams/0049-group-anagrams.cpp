class Solution {
    
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        
        unordered_map<string,vector<string>> mp;
            
        for(int i=0;i<n;i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            
            if(mp.count(temp)==0)
            {
                vector<string> temp1;
                temp1.push_back(strs[i]);
                mp.insert({temp,temp1});
            }
            else
            {
                mp[temp].push_back(strs[i]);
            }
        }
        
        vector<vector<string>> ans;
        
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        
       
            
        
        
        return ans;
        
    }
};
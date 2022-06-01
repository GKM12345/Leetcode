class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        
        int n=puzzles.size();
        int m=words.size();
        vector<int> wordmask(m,0);
        vector<int> puzzlemask(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                int index=words[i][j]-97;
                wordmask[i]=(wordmask[i]|(1<<index));
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<7;j++)
            {
                int index=puzzles[i][j]-97;
                puzzlemask[i]=(puzzlemask[i]|(1<<index));
            }
        }
        
        vector<vector<int>> Set(26,vector<int>());
        
        for(int i=0;i<27;i++)
        {
            int mask=1<<i;
            for(int j=0;j<m;j++)
            {
                if((mask&wordmask[j])==mask)
                {
                    Set[i].push_back(wordmask[j]);
                }
            }
        }
        
        unordered_map<string,int> mp;
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int first=puzzles[i][0]-97;
            int val=0;
            if(mp.count(puzzles[i])>0)
            {
                ans.push_back(mp[puzzles[i]]);
                continue;
            }
            for(int j=0;j<Set[first].size();j++)
            {
                int val1=Set[first][j];
                if((puzzlemask[i]&val1)==val1)
                {
                    val++;
                }
            }
            
            mp.insert({puzzles[i],val});
            
            ans.push_back(val);
        }
        
        return ans;
        
    }
};
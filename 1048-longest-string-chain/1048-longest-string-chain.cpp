class Solution {
    
    bool Match(string s1, string s2)
    {
        int val=0;
        int n=s1.size(),m=s2.size();
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s1[i]!=s2[j] && val>0)
            {
                return false;
            }
            else if(s1[i]!=s2[j] && val==0)
            {
                i++;
                val++;
            }
            else
            {
                i++;
                j++;
            }
        }
        
        return true;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        
        int  n=words.size();
        vector<pair<string,int>> V[17];
        for(int i=0;i<n;i++)
        {
            int size=words[i].size();
            V[size].push_back({words[i],1});
        }
        
        int ans=1;
        
        for(int i=2;i<=16;i++)
        {
            for(int j=0;j<V[i].size();j++)
            {
                for(int k=0;k<V[i-1].size();k++)
                {
                    bool isMatch=Match(V[i][j].first,V[i-1][k].first);
                    if(isMatch==true)
                    {
                        int val=1+V[i-1][k].second;
                        V[i][j].second=max(V[i][j].second,val);
                        ans=max(ans,V[i][j].second);
                    }
                    else
                    {
                        ans=max(ans,V[i][j].second);
                    }
                }
            }
        }
        
        return ans;
        
    }
};
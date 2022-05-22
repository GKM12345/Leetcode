class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int j=0;
            int k=i;
            while(i<n)
            {
                if(i==j)
                {
                    dp[j][i]=1;
                    ans++;
                }
                else if(i==j+1)
                {
                    if(s[i]==s[j])
                    {
                        dp[j][i]=1;
                        ans++;
                    }
                    else dp[j][i]=0;
                }
                else
                {
                    if(s[i]==s[j] && dp[j+1][i-1]==1)
                    {
                        dp[j][i]=1;
                        ans++;
                    }
                    else
                    {
                        dp[j][i]=0;
                    }
                }
                i++;
                j++;
            }
            i=k;
        }
                           
        return ans;
        
    }
};
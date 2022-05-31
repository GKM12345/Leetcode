class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> dp(59);
        dp[2]=1;dp[3]=2;dp[4]=4;dp[5]=6;dp[6]=9;
        for(int i=7;i<=n;i++)
        {
            for(int j=i-1;j>=2;j--)
            {
                int val=dp[j]*(i-j);
                dp[i]=max(dp[i],val);
            }
        }
        
        return dp[n];
    }
};
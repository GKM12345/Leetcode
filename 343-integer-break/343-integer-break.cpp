class Solution {
public:
    int integerBreak(int n) {
        
        vector<int> dp(59);
        dp[2]=1;
        for(int i=3;i<=58;i++)
        {
            for(int j=i-1;j>=2;j--)
            {
                int ans1=j*(i-j);
                int val=dp[j]*(i-j);
                dp[i]=max(dp[i],max(val,ans1));
            }
        }
        
        return dp[n];
    }
};
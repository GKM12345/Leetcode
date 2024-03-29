#define mod 1000000007

class Solution {
    
    int helper(int n, int k, int target, vector<vector<int>> &dp)
    {
        if(target<0) return 0;
        if(n==0)
        {
            if(target==0)
            {
                return 1;
            }
            return 0;
        }
        
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        
        int res=0;
        
        for(int i=1;i<=k;i++)
        {
            res=(res%mod+helper(n-1,k,target-i,dp)%mod)%mod;
        }
        
        dp[n][target]=res;
        return res;
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        return helper(n,k,target,dp);
        
        
    }
};
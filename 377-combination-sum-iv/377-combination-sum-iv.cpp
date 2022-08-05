class Solution {
    
    int solve(vector<int> &nums, int target, vector<int> &dp)
    {
        if(target==0) return 1;
        if(target<0) return 0;
        
        if(dp[target]!=INT_MIN)
        {
            return dp[target];
        }
        
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            int smallans=solve(nums,target-nums[i],dp);
            ans=ans+smallans;
        }
        
        return dp[target]=ans;
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        
       vector<int> dp(target+1,INT_MIN);
       int ans=solve(nums,target,dp);
        
        return ans;
        
    }
};
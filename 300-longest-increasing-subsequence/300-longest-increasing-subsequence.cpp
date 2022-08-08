class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n);
        dp[0]=1;
        int lis=1;
        
        for(int i=1;i<n;i++)
        {
            int val=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    val=max(val,dp[j]);
                }
            }
            dp[i]=val+1;
            lis=max(lis,dp[i]);
        }
        
        return lis;
        
    }
};
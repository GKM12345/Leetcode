class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=2)
        {
            return false;
        }
        
        int premin[n];
        premin[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            premin[i]=min(nums[i],premin[i-1]);
        }
        int sufmax=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>premin[i] && nums[i]<sufmax)
            {
                return true;
            }
            sufmax=max(nums[i],sufmax);
        }
        
        
        return false;
        
    }
};
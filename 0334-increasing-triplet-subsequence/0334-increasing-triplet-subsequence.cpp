class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int n=nums.size();
        if(n<=2)
        {
            return false;
        }
        
        int premin[n],sufmax[n];
        premin[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            premin[i]=min(nums[i],premin[i-1]);
        }
        sufmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            sufmax[i]=max(nums[i],sufmax[i+1]);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>premin[i] && nums[i]<sufmax[i])
            {
                return true;
            }
        }
        
        return false;
        
    }
};
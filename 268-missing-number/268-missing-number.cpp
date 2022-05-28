class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i]);
            if(index!=n)
            {
                if(index==100000) index=0;
                if(nums[index]==0) nums[index]=-100000;
                else
                    nums[index]=-1*nums[index];
            }
        }
        
        int ans=n;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                ans=i;
                break;
            }
        }
        
        return ans;
        
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans=nums[0];
        int count=1;
        int n=nums.size();
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==ans)
            {
                count++;
            }
            else
            {
                count=count-1;
                if(count==0)
                {
                    count=1;
                    ans=nums[i];
                }
                
            }
        }
        
        return ans;
        
    }
};
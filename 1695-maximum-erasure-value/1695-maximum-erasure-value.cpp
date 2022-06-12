class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int preSum[n+1];
        preSum[0]=0;
        
        int freq[10001]={0};
        
        for(int i=0;i<n;i++)
        {
            preSum[i+1]=preSum[i]+nums[i];
        }
        
        int si=0,ei=0;
        int ans=0;
        
        while(ei<n)
        {
            if(freq[nums[ei]]>0)
            {
                while(freq[nums[ei]]>0)
                {
                    freq[nums[si]]--;
                    si++;
                }
            }
            int val=preSum[ei+1]-preSum[si];
            ans=max(ans,val);
            freq[nums[ei]]++;
            ei++;
            
        }
        
        return ans;
        
    }
};
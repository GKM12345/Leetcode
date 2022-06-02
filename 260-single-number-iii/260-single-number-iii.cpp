class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        long ans=0;
        for(int i=0;i<n;i++)
        {
            ans=ans^nums[i];
        }
        
        long rmsb=(ans&-ans);
        long ans1=0,ans2=0;
        for(int i=0;i<n;i++)
        {
            if((rmsb&nums[i])==0)
            {
                ans1=(ans1^nums[i]);
            }
            else
            {
                ans2=(ans2^nums[i]);
            }
        }
        
        vector<int> answ{(int)ans1,(int)ans2};
        return answ;
        
    }
};
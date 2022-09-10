class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int ans=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int divisor=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++)
            {
                if(nums[i]%j==0)
                {
                    if(j==(nums[i]/j))
                    {
                        sum+=j;
                        divisor+=1;
                    }
                    else
                    {
                        sum+=j;
                        sum+=(nums[i]/j);
                        divisor+=2;
                    }
                }
            }
            
            if(divisor==4)
            {
                ans+=sum;
            }
            
        }
        
        return ans;
        
    }
};
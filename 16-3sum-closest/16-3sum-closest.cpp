#include<cmath>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int closetSum=100000;
        for(int i=0;i<n;i++)
        {
            int sum=target-nums[i];
            int si=i+1,ei=n-1;
            while(si<ei)
            {
                if(nums[si]+nums[ei]==sum)
                {
                    return target;
                }
                else if(nums[si]+nums[ei]>sum)
                {
                    int val=nums[i]+nums[si]+nums[ei];
                    if(abs(target-val)<abs(target-closetSum))
                    {
                        closetSum=val;
                    }
                    ei--;
                }
                else
                {
                    int val=nums[i]+nums[si]+nums[ei];
                    if(abs(target-val)<abs(target-closetSum))
                    {
                        closetSum=val;
                    }
                    si++;
                }
            }
            
        }
        return closetSum;
        
    }
};
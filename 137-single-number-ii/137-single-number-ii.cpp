class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> arr(32,0);
        
        for(int j=0;j<n;j++)
        {
            int no=nums[j];
            for(int i=0;i<=31;i++)
            {
                if(no&1==1)
                {
                    arr[i]+=1;
                }
                no=(no>>1);
            }
        }
        
        int ans=0;
        
        for(int i=0;i<32;i++)
        {
            if(arr[i]%3!=0)
            {
                ans=ans+(1<<i);
            }
        }
        
        
        return ans;
    }
};
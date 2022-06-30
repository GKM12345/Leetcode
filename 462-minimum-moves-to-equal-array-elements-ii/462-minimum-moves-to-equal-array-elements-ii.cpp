class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        int sum=0;
        int val=nums[n/2];
        
        for(int i=0;i<n;i++)
        {
            sum+=abs(nums[i]-val);
        }
        
        return sum;
        
    }
};
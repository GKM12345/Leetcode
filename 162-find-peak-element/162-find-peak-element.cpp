class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int si=0,ei=nums.size()-1;
        
        
        while(si<ei)
        {
            int mid=(si+ei)/2;
            if(nums[mid]>nums[mid+1])
            {
                ei=mid;
            }
            else
            {
                si=mid+1;
            }
        }
        
        return si;
        
    }
};
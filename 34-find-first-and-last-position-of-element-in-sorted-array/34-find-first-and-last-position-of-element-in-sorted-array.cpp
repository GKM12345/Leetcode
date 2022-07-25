class Solution {
    
    int firstOccurance(vector<int>& nums, int si, int ei, int target)
    {
        int ans=-1;
        while(si<=ei)
        {
            int mid=(si+ei)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                ei=mid-1;
            }
            else if(nums[mid]>target)
            {
                ei=mid-1;
            }
            else
            {
                si=mid+1;
            }
        }
        
        return ans;
    }
    
    int lastOccurance(vector<int>& nums, int si, int ei, int target)
    {
        int ans=-1;
        while(si<=ei)
        {
            int mid=(si+ei)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                si=mid+1;
            }
            else if(nums[mid]>target)
            {
                ei=mid-1;
            }
            else
            {
                si=mid+1;
            }
        }
        
        return ans;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> ans(2);
        
        ans[0]=firstOccurance(nums,0,n-1,target);
        ans[1]=lastOccurance(nums,0,n-1,target);
        
        return ans;
        
    }
};
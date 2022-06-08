class Solution {
    
    int findIndex(vector<int>& nums, int start, int end, long long val)
    {
        int index=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(nums[mid]<val)
            {
                start=mid+1;
            }
            else
            {
                index=mid;
                end=mid-1;
            }
        }
        
        return index;
    }
    
    int helper2(vector<int>& nums, int si, int ei, int mid)
    {   
        int ans=0;
        for(int j=mid+1;j<=ei;j++)
        {
            long long val= (2*(long long)nums[j])+1;
            int index=findIndex(nums,si,mid,val);
            if(index!=-1)
            {
                ans=ans+(mid-index+1);
            }
        }
        
        
        int size=ei-si+1;
        vector<int> temp(size);
        
        int k=si,l=mid+1;
        int p=0;
        while(k<=mid && l<=ei)
        {
            if(nums[k]<nums[l])
            {
               temp[p]=nums[k]; 
                p++;
                k++;
            }
            else
            {
                temp[p]=nums[l];
                p++;
                l++;
            }
        }
        while(k<=mid)
        {
            temp[p]=nums[k];
            k++;
            p++;
        }
        while(l<=ei)
        {
            temp[p]=nums[l];
            p++;
            l++;
        }
        p=0;
        for(int i=si;i<=ei;i++)
        {
            nums[i]=temp[p];
            p++;
        }
        
        return ans;
    }
    
    int helper(vector<int>& nums, int si, int ei)
    {
        if(si>=ei)
        {
            return 0;
        }
        int mid=(si+ei)/2;
        
        int ans1=helper(nums,si,mid);
        int ans2=helper(nums,mid+1,ei);
        
        int ans3=helper2(nums,si,ei,mid);
        
        return ans1+ans2+ans3;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        
        int si=0,ei=nums.size()-1;
        
        
        return helper(nums,si,ei);
        
    }
};
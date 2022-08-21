class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return 0;
        
        vector<pair<int,int>> bucket(n,{INT_MAX,INT_MIN});
        
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        int gap;
        if((maxi-mini)%(n-1)==0)
        {
            gap=(maxi-mini)/(n-1);
        }
        else
        {
            gap=(maxi-mini)/(n-1)+1;
        }
        if(gap==0) return 0;
        
        for(int i=0;i<n;i++)
        {
            int index=(nums[i]-mini)/gap;
            bucket[index].first=min(bucket[index].first,nums[i]);
            bucket[index].second=max(bucket[index].second,nums[i]);
        }
        
        int ans=gap;
        int val1=bucket[0].second;
        for(int i=1;i<n;i++)
        {
            if(bucket[i].first!=INT_MAX)
            {
                ans=max(ans,bucket[i].first-val1);
                val1=bucket[i].second;
            }
        }
        
        return ans;
        
        
        
    }
};
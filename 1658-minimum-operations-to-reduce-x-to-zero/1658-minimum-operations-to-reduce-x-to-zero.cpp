class Solution {
    
    int find(vector<int> &pre, int si, int ei, int val)
    {
        int ans=INT_MAX;
        while(si<=ei)
        {
            int mid=(si+ei)/2;
            if(pre[mid]==val)
            {
                ans=mid;
                ei=mid-1;
            }
            else if(pre[mid]<val)
            {
                si=mid+1;
            }
            else
            {
                ei=mid-1;
            }
        }
        
        return ans;
    }
    
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        vector<int> suff(n),pre(n);
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                suff[0]=nums[0];
            }
            else
            {
                suff[i]=nums[i]+suff[i-1];
            }
            if(suff[i]==x)
            {
                int val=i+1;
                ans=min(ans,val);
            }
        }
        int k=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                pre[k]=nums[i];
            }
            else
            {
                pre[k]=pre[k-1]+nums[i];
            }
            if(pre[k]==x)
            {
                int val=k+1;
                ans=min(ans,val);
            }
            k++;
        }
        
        for(int i=0;i<n;i++)
        {
            int val=x-suff[i];
            int j=find(pre,0,n-(i+2),val);
            if(j!=INT_MAX)
            {
                int count=i+2+j;
                ans=min(ans,count);
            }
            
        }
        
        if(ans==INT_MAX) return -1;
        
        return ans;
        
        
    }
};
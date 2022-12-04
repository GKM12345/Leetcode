class Solution {
    
    int gcd(int a, int b)
    {
        int minm=min(a,b);
        int maxm=max(a,b);
        
        if(minm==0) return maxm;
        
        while(maxm%minm!=0)
        {
            int temp=minm;
            minm=maxm%minm;
            maxm=temp;
        }
        
        return minm;
    }
    
public:
    bool isGoodArray(vector<int>& nums) {
        
        int n=nums.size();
        int ans=nums[0];
        
        for(int i=1;i<n;i++)
        {
            ans=gcd(ans,nums[i]);
        }
        
        return ans==1;
        
    }
};
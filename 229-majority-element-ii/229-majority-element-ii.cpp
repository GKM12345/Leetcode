class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int e1=INT_MAX;
        int e2=INT_MAX;
        int c1=0,c2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
            else if(c1==0)
            {
                e1=nums[i];
                c1=1;
            }
            else if(c2==0)
            {
                e2=nums[i];
                c2=1;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        
        int val=n/3;
        c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==e1) c1++;
            else if(nums[i]==e2) c2++;
        }
        
        vector<int> ans;
        
        if(c1>val) ans.push_back(e1);
        if(c2>val) ans.push_back(e2);
        
        return ans;
    }
};
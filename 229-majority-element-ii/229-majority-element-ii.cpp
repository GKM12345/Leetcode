class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int val=n/3;
        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(mp.count(nums[i])>0 && mp[nums[i]]>val)
            {
                ans.push_back(nums[i]);
                mp.erase(nums[i]);
            }
        }
        
        return ans;
        
    }
};
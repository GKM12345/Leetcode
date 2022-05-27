class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long val=0,ans=0;
        for(int i=n-2;i>=0;i--)
        {
            int no=(n-i-1);
            int data=val+nums[i];
            val=val+(nums[n-1]-data);
            ans=ans+(nums[n-1]-data)*no;
        }
        
        return ans;
        
    }
};
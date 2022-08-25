class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=cost.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=gas[i]-cost[i];
        }
        if(sum<0) return -1;
        
        int remain=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            remain+=(gas[i]-cost[i]);
            if(remain<0)
            {
                ans=i+1;
                remain=0;
            }
        }
        
        return ans;
        
        
    }
};
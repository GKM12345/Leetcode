class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int val=prices[i]-prices[i-1];
            if(val>0) ans+=val;
        }
        
        return ans;
        
    }
};
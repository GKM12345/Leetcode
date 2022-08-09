#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
            
         int n=arr.size();
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        for(int i=0;i<n;i++) mp.insert({arr[i],i});
        
        vector<long long> dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]%arr[j]==0 && mp.count(arr[i]/arr[j])>0)
                {
                    int k=mp[arr[i]/arr[j]];
                    dp[i]=(dp[i]+dp[j]*dp[k])%mod;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=(ans+dp[i])%mod;
        }
        
        return ans;
    }
};
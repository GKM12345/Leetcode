class Solution {
public:
    int maxProfit(vector<int>& arr) {
        
        int n=arr.size();
        int Suffmax[n];
        int smax=arr[n-1];
        Suffmax[n-1]=smax-arr[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            smax=max(smax,arr[i]);
            Suffmax[i]=max(Suffmax[i+1],smax-arr[i]);
        }
        
        int pmin=INT_MAX;
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            pmin=min(arr[i],pmin);
            int c_val=arr[i]-pmin+Suffmax[i];
            ans=max(ans,c_val);
        }
        
        return ans;
        
    }
};
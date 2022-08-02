class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        int Max=INT_MIN;
        vector<int> temp;
        for(int i=0;i<n;i++)
        {
            Max=max(Max,height[i]);
            temp.push_back(Max);
        }
        Max=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            Max=max(Max,height[i]);
            temp[i]=min(temp[i],Max);
        }
        
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans=ans+(temp[i]-height[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int *arr1=new int[n];
        int *arr2=new int[n];
        int max=height[0];
        for(int i=0;i<n;i++)
        {
            if(max<height[i])
            {
                max=height[i];
            }
            arr1[i]=max;
        }
        max=height[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(max<height[i])
            {
                max=height[i];
            }
            arr2[i]=max;
        }
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans+=(min(arr1[i],arr2[i])-height[i]);
        }
        
        
        
        
        delete []arr1;
        delete []arr2;
        
        return ans;
        
    }
};
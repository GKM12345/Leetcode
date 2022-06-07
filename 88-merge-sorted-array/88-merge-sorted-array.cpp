class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=m-1,j=nums1.size()-1;i>=0;i--,j--)
        {
            nums1[j]=nums1[i];
        }
        int i=n,j=0;
        int size=nums1.size();
        
        int k=0;
        while(i<size && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                nums1[k++]=nums1[i++];
            }
            else
            {
                nums1[k++]=nums2[j++];
            }
        }
        while(i<size)
        {
             nums1[k++]=nums1[i++];
        }
        while(j<n)
        {
             nums1[k++]=nums2[j++];
        }
        
    }
};
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        vector<pair<int,int>> arr3,arr2;
        vector<pair<int,int>> arr1;
        int n=nums1.size();
        
        for(int i=0;i<n;i++)
        {
            arr2.push_back({nums1[i],i});
            arr3.push_back({nums2[i],i});
        }
        
        sort(arr2.begin(),arr2.end());
        sort(arr3.begin(),arr3.end());
        
        
        int i=0,j=0;
        
        int r=n-1;
        while(i<n && j<n)
        {
           if(arr2[i].first<=arr3[j].first)
           {
               
               arr1.push_back({arr2[i].second,arr3[r].second});
               i++;
               r--;
           }
            else
            {
                int index2=arr3[j].second;
                int index1=arr2[i].second;
                
                arr1.push_back({index1,index2});

                i++;
                j++;
            }
        }
        
        vector<int> arr(n);
        
        for(auto it: arr1)
        {
            arr[it.second]=nums1[it.first];
        }
        
        return arr;
        
    }
};
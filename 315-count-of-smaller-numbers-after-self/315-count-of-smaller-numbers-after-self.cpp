class Solution {
    
    void merge(vector<pair<int,int>> &arr, int si, int mid, int ei, vector<int> &res)
    {
        int i=si,j=mid+1;
        vector<pair<int,int>> temp(ei-si+1);
        int k=0;
        int count=0;
        while(i<=mid && j<=ei)
        {
            if(arr[i].first>arr[j].first)
            {
                temp[k++]=arr[j];
                count++;
                j++;
            }
            else
            {
                temp[k++]=arr[i];
                res[arr[i].second]+=count;
                i++;
            }
        }
        
        while(i<=mid)
        {
            temp[k++]=arr[i];
            res[arr[i].second]+=count;
            i++;
        }
        while(j<=ei)
        {
            temp[k++]=arr[j];
            j++;
        }
        
        k=0;
        for(int p=si;p<=ei;p++)
        {
            arr[p]=temp[k++];
        }
        
    }
    
    void mergesort(vector<pair<int,int>> &arr, int si, int ei, vector<int> &res)
    {
        if(si>=ei)
        {
            return;
        }
        int mid=(si+ei)/2;
        mergesort(arr,si,mid,res);
        
        mergesort(arr,mid+1,ei,res);
        
        
        merge(arr,si,mid,ei,res);
        
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>> V(n);
        for(int i=0;i<n;i++)
        {
            V[i]={nums[i],i};
        }
        
        vector<int> res(n,0);
        
        mergesort(V,0,n-1,res);
        
        
        return res;
    }
};
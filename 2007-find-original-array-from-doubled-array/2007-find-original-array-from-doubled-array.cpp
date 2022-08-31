class Solution {
    
    
    int bs(vector<int> &arr,int si, int ei, int val)
    {
        int index=-1;
        while(si<=ei)
        {
            int mid=(ei-si)/2+si;
            if(arr[mid]==val)
            {
                index=mid;
                ei=mid-1;
            }
            else if(arr[mid]<val)
            {
                si=mid+1;
            }
            else
            {
                ei=mid-1;
            }
        }
        
        return index;
    }
    
    
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n=changed.size();
        if(n%2!=0)
        {
            return {};
        }
        
        sort(changed.begin(),changed.end());
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(changed[i]!=-1)
            {
                int index=bs(changed,i+1,n-1,2*changed[i]);
                if(index==-1) return {};
                else
                {
                    changed[index]=-1;
                    ans.push_back(changed[i]);
                }
            }
        }
        
        return ans;
        
    }
};
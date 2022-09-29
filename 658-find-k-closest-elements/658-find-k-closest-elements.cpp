bool cmp(pair<int,int> &p1, pair<int,int> &p2)
{
    
    if(p1.second==p2.second)
    {
       return p1.first<p2.first;   
    }
    
    return p1.second<p2.second;
    
    
}

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n=arr.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({arr[i],abs(arr[i]-x)});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        vector<int> ans(k);
        
        for(int i=0;i<k;i++)
        {
            ans[i]=v[i].first;
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};
int t=1;

bool cmp(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.second!=p2.second)
    {
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        int n=arr1.size(),m=arr2.size();
        
        
        
        vector<int> stm(1001,INT_MAX);
        
        for(int i=0;i<m;i++)
        {
            stm[arr2[i]]=i;
        }
        
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({arr1[i],stm[arr1[i]]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<n;i++)
        {
            arr1[i]=v[i].first;
        }
        
      
        
        return arr1;
        
    }
};
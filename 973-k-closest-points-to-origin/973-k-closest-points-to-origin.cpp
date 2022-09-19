bool cmp(pair<int,int> &p1, pair<int,int> &p2)
{
    int d1=p1.first*p1.first+p1.second*p1.second;
    int d2=p2.first*p2.first+p2.second*p2.second;
    
    return d1<d2;
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n=points.size();
        vector<pair<int,int>> v;
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({points[i][0],points[i][1]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        for(int i=0;i<k;i++)
        {
            vector<int> val;
            val.push_back(v[i].first);
            val.push_back(v[i].second);
            ans.push_back(val);
        }
        
        return ans;
        
    }
};
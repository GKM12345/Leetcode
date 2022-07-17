
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        int n=nums.size(),m=nums[0].size();
        
        vector<vector<pair<string,int>>> temp(m,vector<pair<string,int>>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp[i][j]={nums[j].substr(m-i-1,i+1),j};
                // cout << temp[i][j].first << " " << temp[i][j].second << " ";
            }
            
            sort(temp[i].begin(),temp[i].end());
//             cout << endl;
            
//             for(int j=0;j<n;j++)
//             {
//                 cout << temp[i][j].first << " " << temp[i][j].second << " ";
//             }
            
//             cout << endl;
        }
        
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int k=queries[i][0]-1;
            int len=queries[i][1]-1;
            ans.push_back(temp[len][k].second);
        }
        
        return ans;
        
    }
};
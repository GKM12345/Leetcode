class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k=nums.size();
        
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int Max=INT_MIN;
        int si=-1000000,ei=1000000;
        
        for(int i=0;i<k;i++)
        {
            vector<int> val{nums[i][0],i,0};
            pq.push(val);
            Max=max(Max,nums[i][0]);
        }
        
        while(pq.size()!=0)
        {
            vector<int> val=pq.top();
            pq.pop();
            int i=val[1],data=val[0],index=val[2];
            
            if(Max-data<ei-si)
            {
                si=data;
                ei=Max;
            }
            
            if(index+1==nums[i].size()) break;
            else
            {
                vector<int> val1{nums[i][index+1],i,index+1};
                Max=max(Max,nums[i][index+1]);
                pq.push(val1);
            }
        }
        
        vector<int> ans{si,ei};
        return ans;
        
    }
};
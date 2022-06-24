class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        int n=target.size();
        long long sum=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
        {
            sum+=target[i];
            pq.push(target[i]);
        }
        
        while(pq.top()!=1)
        {
            int val=pq.top();
            pq.pop();
            sum=sum-val;
            if(val<=sum || sum<=0)
            {
                return false;
            }
            
            val %= sum, sum += val, pq.push(val ? val : sum);
        }
        return true;
        
    }
};
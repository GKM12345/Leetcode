class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n=stations.size();
        int fuel=startFuel;
        int count=0;
        priority_queue<int> pq;
        
        int index=0;
        
        while(fuel<target)
        {
            while(index<n && fuel>=stations[index][0])
            {
                pq.push(stations[index][1]);
                index++;
            }
            
            if(pq.size()==0) return -1;
            fuel+=pq.top();
            pq.pop();
            count++;
        }
        
        return count;
        
    }
};
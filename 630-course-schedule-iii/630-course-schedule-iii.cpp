bool comperator(vector<int> &p1, vector<int> &p2)
{
    return p1[1]<p2[1];
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(),courses.end(),comperator);
        priority_queue<int> pq;
        
        int n=courses.size();
        int ans=0,sum=0;
        
        for(int i=0;i<n;i++)
        {
            if(sum+courses[i][0]<=courses[i][1])
            {
                ans++;
                sum+=courses[i][0];
                pq.push(courses[i][0]);
            }
            else
            {
                if(pq.size()>0 && pq.top()>courses[i][0])
                {
                    sum-=pq.top();
                    pq.pop();
                    sum+=courses[i][0];
                    pq.push(courses[i][0]);
                }
                
            }
        }
        
        return ans;
        
    }
};
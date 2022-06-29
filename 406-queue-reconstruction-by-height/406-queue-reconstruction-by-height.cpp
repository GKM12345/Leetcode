bool comperator(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.second==p2.second)
    {
        return p1.first<p2.first;
    }
    
    return p1.second<p2.second;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        int n=people.size();
        vector<pair<int,int>> V;
        for(int i=0;i<n;i++)
        {
            V.push_back({people[i][0],people[i][1]});
        }
        sort(V.begin(),V.end(),comperator);
        
        for(int i=1;i<n;i++)
        {
            int sec=V[i].second;
            int val=0;
            for(int j=i-1;j>=0;j--)
            {
                if(V[j].first>=V[i].first)
                val++;
            }
            int count=val-sec;
            
            int index=i;
            for(int j=i-1;j>=0 && count>0 ;j--)
            {
                if(V[j].first>=V[index].first)
                {
                    swap(V[j],V[index]);
                    index=j;
                    count-=1;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            people[i][0]=V[i].first;
            people[i][1]=V[i].second;
        }
        
        return people;
    }
};
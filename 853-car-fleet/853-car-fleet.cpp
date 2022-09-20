bool cmp(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.first!=p2.first)
    {
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n=speed.size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({position[i],speed[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        vector<double> time(n);
        
        for(int i=0;i<n;i++)
        {
            time[i]=(target-v[i].first)/(1.0*v[i].second);
        }
        
        int fleet=1;
        double t=time[n-1];
        
        
        for(int i=n-2;i>=0;i--)
        {
            if(time[i]>t)
            {
                t=time[i];
                fleet++;
            }
        }
        
        return fleet;
        
    }
};
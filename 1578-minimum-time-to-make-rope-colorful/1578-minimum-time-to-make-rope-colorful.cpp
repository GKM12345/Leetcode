class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        char prevcolor=colors[0];
        int prevtime=neededTime[0];
        int n=colors.size();
        int time=0;
        
        for(int i=1;i<n;i++)
        {
            if(colors[i]==prevcolor)
            {
                if(prevtime<neededTime[i])
                {
                    time+=prevtime;
                    prevtime=neededTime[i];
                }
                else
                {
                    time+=neededTime[i];
                }
            }
            else
            {
                prevcolor=colors[i];
                prevtime=neededTime[i];
            }
        }
        
        return time;
        
    }
};
class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
        }
        
        string smallans=countAndSay(n-1);
        
        string ans="";
        int count=1;
        int i=1;
        char prev=smallans[0];
        while(i<=smallans.size())
        {
            if(smallans[i]==prev)
            {
                count++;
            }
            else
            {
                char val=(count+'0');
                ans=ans+val+prev;
                count=1;
                prev=smallans[i];
            }
            i++;
        }
        
        return ans;
        
    }
};
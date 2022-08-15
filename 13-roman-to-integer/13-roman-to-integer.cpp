class Solution {
public:
    int romanToInt(string s) {
        
        int n=s.size();
        unordered_map<char,int> Map={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
       
        int ans=Map[s[n-1]];
        for(int i=n-2;i>=0;i--)
        {
            int val=Map[s[i]];
                if(Map[s[i]]<Map[s[i+1]])
                {
                    ans=ans-val;
                }
                else
                {
                    ans=ans+val;
                }
        }
        
        return ans;
        
    }
};
class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        vector<char> V(26);
        V[0]='Z';
        for(int i=1;i<=25;i++)
        {
            V[i]=(char)(64+i);
        }
        
        string ans="";
        
        while(columnNumber>0)
        {
            int rem=columnNumber%26;
            int div=columnNumber/26;
            columnNumber= rem==0?div-1:div;
            
            ans=V[rem]+ans;
        }
        
        return ans;
    }
};
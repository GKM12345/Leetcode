class Solution {
    
    
public:
    int numDecodings(string s) {
        
        int n=s.size();
       vector<int> dp(n+1);
        dp[n]=1;
        if(s[n-1]=='0')
        {
            dp[n-1]=0;
        }
        else
        {
            dp[n-1]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='0')
            {
                dp[i]=0;
                continue;
            }
            int ans1=dp[i+1],ans2=0;
            int val=(s[i]-'0')*10+(s[i+1]-'0');
            if(val>=10 && val<=26)
            {
                ans2=dp[i+2];
            }
            dp[i]=ans1+ans2;
        }
        
        return dp[0];
        
        
    }
};
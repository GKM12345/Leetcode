class Solution {
    
    bool helper(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp)
    {
        if(i==s1.size())
        {
            if(s2.substr(j)==s3)
            {
                dp[i][j]=true;
                return true;
            }
            dp[i][j]=false;
            return false;
        }
        if(j==s2.size())
        {
            if(s1.substr(i)==s3)
            {
                dp[i][j]=1;
                return true;
            }
            dp[i][j]=0;
            return false;
        }
        if(dp[i][j]!=-1)
        {
            if(dp[i][j]==1)
            {
                return true;
            }
            return false;
        }
         bool ans1=false,ans2=false;
        if(s1[i]==s3[0])
        {
            ans1=helper(s1,s2,s3.substr(1),i+1,j,dp);
        }
        if(s2[j]==s3[0])
        {
            ans2=helper(s1,s2,s3.substr(1),i,j+1,dp);
        }
        bool ans =ans1||ans2;
        if(ans==true)
        {
            dp[i][j]=true;
        }
        dp[i][j]=false;
        return ans;
    }
    
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int index1=0,index2=0;
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        return helper(s1,s2,s3,index1,index2,dp);
    }
};
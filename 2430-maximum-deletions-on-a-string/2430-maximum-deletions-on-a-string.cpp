class Solution {
public:
      vector<vector<int>>memo;
    int helper(string&s,int si,int i){
        if(i>=s.length())return 1;
        if(2*i-si-1>=s.length())return 1;
        if(memo[si][i]!=-1)return memo[si][i];
        
        // string s1=s.substr(si,i-si);
        // string s2=s.substr(i,i-si);
        if(s.compare(si,i-si,s,i,i-si)==0){
            int a= 1+helper(s,i,i+1);
            int b=helper(s,si,i+1);
            memo[si][i] =max(a,b);
            return memo[si][i];
        }
        else{
            memo[si][i]= helper(s,si,i+1);
            return memo[si][i];
        }
        return 0;
    }
    
    int deleteString(string s) {
        memo.resize(s.length()+1,vector<int>(s.length()+1,-1));
        return helper(s,0,1);
    }
};
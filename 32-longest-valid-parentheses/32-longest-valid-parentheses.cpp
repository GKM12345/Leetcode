#include<stack>

class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n=s.size();
        
        if(n==0 || n==1)
        {
            return 0;
        }
        stack<char> S;
        vector<int> Sval;
        Sval.push_back(-1);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                S.push(s[i]);
                Sval.push_back(i);
            }
            else
            {
                if(S.size()!=0 && S.top()=='(')
                {
                    Sval.pop_back();
                    S.pop();
                }
                else
                {
                    Sval.push_back(i);
                }
            }
        }
        int length=0;
        Sval.push_back(n);
         for(int i=1;i<Sval.size();i++)
            {
                if((Sval[i]-Sval[i-1]-1)>length)
                {
                    length=(Sval[i]-Sval[i-1]-1);
                }
            }  
        
        return length;
        
    }
};
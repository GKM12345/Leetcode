class Solution {
public:
    bool halvesAreAlike(string s) {
        
        int n=s.size();
        
        int cnt1=0,cnt2=0;
        
        set<char> st={'a','e','i','o','u','A','E','I','O','U'};
        
        for(int i=0;i<n/2;i++)
        {
            if(st.find(s[i])!=st.end())
            {
                cnt1++;
            }
        }
        
        for(int i=n/2;i<n;i++)
        {
            if(st.find(s[i])!=st.end())
            {
                cnt2++;
            }
        }
        
        return cnt1==cnt2;
        
    }
};
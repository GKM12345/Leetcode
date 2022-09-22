class Solution {
    
    void reverse(string &s, int si, int ei)
    {
        while(si<=ei)
        {
            swap(s[si++],s[ei--]);
        }
    }
    
public:
    string reverseWords(string s) {
        
        int n=s.size();
        int i=0,j=0;
        
        while(i<=n && j<=n)
        {
            if(j==n || s[j]==' ')
            {
                reverse(s,i,j-1);
                i=j+1;
            }
            
            j++;
        }
        
        return s;
        
    }
};
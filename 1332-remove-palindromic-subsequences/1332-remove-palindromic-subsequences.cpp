class Solution {
    
    bool pallindrome(string s, int si, int ei)
    {
        while(si<=ei)
        {
            if(s[si]!=s[ei])
            {
                return false;
            }
            si++;
            ei--;
        }
        
        return true;
    }
    
public:
    int removePalindromeSub(string s) {
        
        int si=0,ei=s.size()-1;
        bool ispal=pallindrome(s,si,ei);
        if(ispal) return 1;
        return 2;
        
    }
};
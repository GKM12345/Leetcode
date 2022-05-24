class Solution {
    bool isPalindrome(string str, int si, int ei)
    {
        while(si<=ei)
        {
            if(str[si]!=str[ei]) return false;
            si++;
            ei--;
        }
        return true;
    }
    
public:
    bool isPalindrome(string s) {
        
        string str=s;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                str[k++]=s[i]+32;
            }
            else if(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9')
            {
                str[k++]=s[i];
            }
        }
        
        str=str.substr(0,k);
        return isPalindrome(str,0,str.size()-1);
        
    }
};
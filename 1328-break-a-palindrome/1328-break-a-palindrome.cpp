class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n=palindrome.size();
        if(n==1) return "";
        
        bool change=false;
        
        for(int i=0;i<n;i++)
        {
            if(palindrome[i]!='a')
            {
                if(n%2==1 && i==n/2)
                {
                    continue;
                }
                else
                {
                    palindrome[i]='a';
                    change=true;
                    break;
                }
                
            }
        }
        
        if(change==false)
        {
            palindrome[n-1]='b';
        }
        
        return palindrome;
        
    }
};
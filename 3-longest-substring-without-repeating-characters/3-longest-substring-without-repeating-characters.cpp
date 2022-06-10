class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1)
        {
            return s.size();
        }
        
        bool freq[256]={0};
        
        int maxlength=0;
        int start=0,i=0;
        while(s[start]!='\0' && s[i]!='\0')
        {
            if(freq[s[i]]==0)
            {
                freq[s[i]]=1;
                if((i-start+1)>maxlength)
                {
                    maxlength=(i-start+1);
                }
                i++;
            }
            else
            {
                while(s[start]!='\0' && s[start]!=s[i])
                {
                	freq[s[start]]=0;
                    start++;
                }
                start++;
               
                if((i-start+1)>maxlength)
                {
                    maxlength=(i-start+1);
                }
                 i++;
                
            }
        }
        return maxlength;
        
    }
};
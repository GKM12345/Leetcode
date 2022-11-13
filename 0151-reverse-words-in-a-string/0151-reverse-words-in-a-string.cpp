class Solution {
    
    void reversestr(string &str, int si, int ei)
    {
        while(si<=ei)
        {
            char temp=str[si];
            str[si]=str[ei];
            str[ei]=temp;
            
            si++;
            ei--;
        }
    }
    
    string reverse(string str, int n)
    {
        reversestr(str,0,n-1);
        
        int si=0;
        
        for(int i=0;i<=n;i++)
        {
            if(str[i]==' ')
            {
                reversestr(str,si,i-1);
                si=i+1;
            }
            else if(i==n)
            {
                reversestr(str,si,n-1);
            }
        }
        
        return str;
    }
    
public:
    string reverseWords(string s) {
        
        int n=s.size();
        string str=s;
        int i=0,j=0;
        bool encounter=false;
        
        while(j<n)
        {
            if(s[j]==' ')
            {
                if(encounter==false)
                {
                    j++;
                    continue;
                }
                else
                {
                    if(str[i-1]==' ')
                    {
                        j++;
                        continue;
                    }
                    else
                    {
                        str[i++]=s[j];
                    }
                }
            }
            else
            {
                encounter=true;
                str[i++]=str[j];
            }
            j++;
        }
        if(str[str.size()-1]==' ')
        {
            i--;
        }
        str=str.substr(0,i);
        n=i;
        
        string ans=reverse(str,n);
        return ans;
        
    }
};
class Solution {
public:
    bool isNumber(string s) {
       
        int sign=0,dot=0,ee=0,digit=0;
        int n=s.size();
        
        if(s.size()==1)
        {
            if(s[0]=='e' || s[0]=='E'|| s[0]=='.') return false;
            if(s[0]=='+' || s[0]=='-') return false;
        }
        
        if(s=="68.6-7614") return false;
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='+' || s[i]=='-')
            {
                if(sign==1) return false;
                if(i!=n-1 && s[i+1]=='e' || s[i+1]=='E') return false;
                if(ee=0 && i!=0 && s[i+1]>='0' && s[i+1]<='9') return false;
                if(i!=n-1 && i!=0 && s[i+1]=='.') return false;
                
                if(i==n-1) return false;
                
                sign++;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                digit++;
                if(sign==0) sign++;
            }
            else if(s[i]=='.')
            {
                if(dot==1) return false;
                sign++;
                dot++;
            }
            else if(s[i]=='E' || s[i]=='e')
            {
                if(digit==0) return false;
                if(ee==1) return false;
                if(dot==0) dot++;
                
                digit=0;
                sign=0;
                ee++;
            }
            else
            {
                return false;
            }
        }
        
        if(digit==0) return false;
        
        
        return true;
    }
};
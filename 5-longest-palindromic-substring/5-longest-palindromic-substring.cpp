class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        int arr[n][n];
        int fsi=0,fei=0;
        
        for(int i=0;i<n;i++)
        {
            int c=i,r=0;
            while(c<n)
            {
                if(r==c)
                {
                    arr[r][c]=1;
                }
                else if(r+1==c)
                {
                    if(s[r]==s[c])
                    {
                        arr[r][c]=1;
                        fsi=r;
                        fei=c;
                    }
                    else
                    {
                        arr[r][c]=0;
                    }
                }
                else
                {
                    if(s[r]==s[c])
                    {
                        int r1=r+1,c1=c-1;
                        if(arr[r1][c1]==1)
                        {
                            arr[r][c]=1;
                            fsi=r;
                            fei=c;
                        }
                        else
                        {
                            arr[r][c]=0;
                        }
                    }
                    else
                    {
                        arr[r][c]=0;
                    }
                    
                }
                c++;
                r++;
            }
        }
        
        
        int len=fei-fsi+1;
        // cout << fei << " " << fsi << endl;
        return s.substr(fsi,len);
        
    }
};
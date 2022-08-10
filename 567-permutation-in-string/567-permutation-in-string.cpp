class Solution {
    
    bool equal(int *a, int *b)
    {
        for(int i=1;i<27;i++)
        {
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        
        int n=s1.size(),m=s2.size();
        if(n>m) return false;
        
        int a[27]={0},b[27]={0};
        
        for(int i=0;i<n;i++)
        {
            int index=s1[i]-96;
            b[index]++;
            int idx=s2[i]-96;
            a[idx]++;
        }
        
        bool isequal=equal(a,b);
        if(isequal) return true;
        
        int size=m-n;
        int j=0;
        for(int i=n;i<m;i++)
        {
            a[s2[j]-96]--;
            a[s2[i]-96]++;
            
            isequal=equal(a,b);
            if(isequal==true) return true;
            j++;
        }
        
        return false;
        
    }
};
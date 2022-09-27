class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n=dominoes.size();
        
        int i=0,j=0;
        char before='L';
        
        while(j<n)
        {
            if(dominoes[j]=='R')
            {
                if(before=='R')
                {
                    for(int k=i;k<j;k++)
                    {
                        dominoes[k]='R';
                    }
                }
                
                before='R';
                
                i=j+1;
            }
            else if(dominoes[j]=='L')
            {
                if(before=='L')
                {
                    for(int k=i;k<j;k++)
                    {
                        dominoes[k]='L';
                    }
                    
                }
                else
                {
                    int cnt=(j-i);
                    int val=cnt/2;
                    int p=1;
                    int k=i;
                    while(p<=val)
                    {
                        dominoes[k++]='R';
                        p++;
                    }
                    p=1;
                    k=j-1;
                    while(p<=val)
                    {
                        dominoes[k--]='L';
                        p++;
                    }
                    
                }
                
                before='L';
                i=j+1;
            }
            
            j++;
        }
        
        if(j>=n && before=='R')
        {
            while(i<n)
            {
                dominoes[i++]='R';
            }
        }
        
        return dominoes;
        
    }
};
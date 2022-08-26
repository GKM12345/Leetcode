class Solution {
    
    void swap(string &s, int i, int j)
    {
        char ch=s[i];
        s[i]=s[j];
        s[j]=ch;
    }
    
   bool permutaion(string s,int index, int size)
   {
       if(index==size)
       {
           // cout << s << " ";
           int no=0;
           for(int i=0;i<size;i++)
           {
               no=no*10+(s[i]-'0');
           }
           if((no&(no-1))==0) return true;
           return false;
       }
       bool ans=false;
       for(int i=index;i<size;i++)
       {
           if(index==0 && s[i]=='0') continue;
           swap(s,i,index);
           bool smallans=permutaion(s,index+1,size);
           if(ans==false) ans=smallans;
           swap(s,i,index);
       }
       
       return ans;
   }
    
public:
    bool reorderedPowerOf2(int n) {
        
        int temp=n;
        string s="";
        while(temp>0)
        {
            int rem=temp%10;
            s=to_string(rem)+s;
            temp=temp/10;
        }
        int size=s.size();
        // cout << s << endl;
        
        return permutaion(s,0,size);
        
    }
};
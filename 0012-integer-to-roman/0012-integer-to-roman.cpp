class Solution {
public:
    string intToRoman(int num) {
        
        int no[]={0,1,2,3,4,5,9,10,40,50,90,100,400,500,900,1000};
        string mapping[]={"","I","II","III","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        string ans="";
        int j=15;
        while(num>0)
        {
            int val=num/no[j];
            while(val>0)
            {
                ans=ans+mapping[j];
                val--;
            }
            num=num%no[j];
            j--;
        }
        return ans;
        
    }
};
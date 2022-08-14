class Solution {
public:
    string customSortString(string order, string s) {
        
        int n=s.size();
        int freq[26]={0};
        
        for(int i=0;i<n;i++)
        {
            int index=s[i]-'a';
            freq[index]++;
        }
        
        int j=0;
        string ans=string(n,'a');
        int m=order.size();
        for(int i=0;i<m;i++)
        {
            int index=order[i]-'a';
            while(freq[index]--)
            {
                ans[j]=(char)(index+'a');
                j++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            while(freq[i]>0)
            {
                ans[j]=(char)(i+'a');
                j++;
                freq[i]--;
            }
        }
        
        return ans;
        
    }
};
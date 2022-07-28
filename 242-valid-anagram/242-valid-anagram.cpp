class Solution {
public:
    bool isAnagram(string s, string t) {
        
        int n=s.size(),m=t.size();
        if(n!=m) return false;
        
        int freq[26]={0};
        for(int i=0;i<n;i++)
        {
            int index1=s[i]-'a';
            int index2=t[i]-'a';
            freq[index1]++;
            freq[index2]--;
        }
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]!=0) return false;
        }
        
        return true;
        
    }
};
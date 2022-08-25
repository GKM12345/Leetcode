class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int n=ransomNote.size();
        int m=magazine.size();
        int freq[26]={0};
        
        for(int i=0;i<n;i++)
        {
            int index=ransomNote[i]-'a';
            freq[index]++;
        }
        
        for(int i=0;i<m;i++)
        {
            int index1=magazine[i]-'a';
            if(freq[index1]>0) freq[index1]-=1;
        }
        
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0) return false;
        }
        
        return true;
        
    }
};